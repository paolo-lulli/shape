<?php
	/**
		Copyright (c) 2007 Mats Lindh
		
		Permission is hereby granted, free of charge, to any person
		obtaining a copy of this software and associated documentation
		files (the "Software"), to deal in the Software without
		restriction, including without limitation the rights to use,
		copy, modify, merge, publish, distribute, sublicense, and/or sell
		copies of the Software, and to permit persons to whom the
		Software is furnished to do so, subject to the following
		conditions:
		
		The above copyright notice and this permission notice shall be
		included in all copies or substantial portions of the Software.
		
		THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
		EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
		OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
		NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
		HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
		WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
		FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
		OTHER DEALINGS IN THE SOFTWARE.
	**/
	
	/**
	 * An implementation of an XML-RPC server component.
	 *
	 * @author Mats Lindh <mats@lindh.no>
	 * @package XRPC
	 * @version 0.0.1 (Unicron)
	 **/

	/**
	 * Escape an string to be used in XML-RPC. The XML-RPC spec only asks for &lt; and &amp; to be escaped.
	 *
	 * @param string $s The string to escape.
	 * @return string The escaped string.
	 **/
	function escape_xmlrpc_string($s)
	{	
		// escape < and &
		return str_replace(array('<', '&'), array('&lt;', '&amp;'), $s);
	}

	/**
	 * A class representing an XML-RPC exception. Has one additional method compared to regular Exceptions, getXML. The getXML-method returns a ready-to-go XML-RPC error document.
	 *
	 * @package XRPC
	 **/
	 
	class XRPC_Exception extends Exception
	{
		/**
		 * Returns the exception as an XML-RPC compatible error message.
		 *
		 * @return string The XML-RPC compatible error message.
		 **/
		 
		public function getXML()
		{
			return '<methodResponse><fault><value><struct><member><name>faultCode</name><value><int>' . ((int)$this->getCode()) . '</int></value></member><member><name>faultString</name><value><string>' . escape_xmlrpc_string($this->getMessage()) . '</string></value></member></struct></value></fault></methodResponse>';
		}
	}

	/**
	 * The XML-RPC server in itself. Instanciate with an associative array containing which methods should be available and their external names.
	 *
	 * @package XRPC
	 * @author Mats Lindh <mats@lindh.no>
	 **/

	class XRPC_Server
	{
		/**
		 * Contains all exported functions available through the XML-RPC server.
		 **/
		private $functionMap = array();
		
		/**
		 * Decides wether to attempt to detect dateTime-fields before returning data to the client.
		 * 
		 * You'll need to turn this on if your application returns iso8601-compatible datefields as strings.
		 **/
		public $detectDateTime = false;
		
		/**
		 * Set this value to true if you want the XML-RPC server to generate DateTime-objects when it receives an iso8601 field. If false, return a iso8601-formatted string.
		 **/
		public $returnDateTimeObject = false;
		
		/**
		 * Constructor for the XRPC_Server-class. 
		 *
		 * @param array $functions An array containing a mapping of the names to export functions under and their internal names. Example: array('getName' => 'get_name_of_customer'). You may also refer to objects by using array(&$obj, 'method')-pairs.
		 **/

		function __construct($functions)
		{
			// Add internal functions (We do this before the other functions are added so that developers can overload the functions)
			$this->functionMap['system.listMethods'] = array(
				'internalFunction' => array(&$this, 'listMethods'),
				'arguments' => array(),
				'docComment' => 'Returns a list of available XML-RPC methods.',
			);

			$this->functionMap['system.methodHelp'] = array(
				'internalFunction' => array(&$this, 'getMethodHelp'),
				'arguments' => array(
					array(
						'name' => 'methodName',
					),
				),
				'docComment' => 'Returns the help string of an available XML-RPC method.',
			);

			// loop through the functions given to the constructor and create internal references for each one.
			// We use the Reflection API introduced in PHP 5.1 to do this.
			foreach($functions as $exportedName => $functionName)
			{
				// Retrieve ReflectionObject..
				$reflection = new ReflectionFunction($functionName);
				$arguments = array();
				// Fetch available parameters..
				$parameters = $reflection->getParameters();
				
				foreach ($parameters as $index => $reflectionParam)
				{
					// store all available arguments..
					$arguments[] = array(
						'name' => $reflectionParam->getName(),
					);
				}
				
				// Get the documentation for the function / method to invoke
				$doc = $reflection->getDocComment();
				
				// Store the externally available function
				$this->functionMap[$exportedName] = array(
					'internalFunction' => $functionName,
					'arguments' => $arguments,
					'docComment' => $doc,
				);
			}
		}
		
		/**
		 * Internal method to return a list of all the available methods.
		 * 
		 * @return array An array of strings containing externally available method names.
		 **/
		private function listMethods()
		{
			$methods = array();
			
			foreach($this->functionMap as $exportedName => $info)
			{
				$methods[] = $exportedName;
			}
			
			return $methods;
		}

		/**
		 * Internal method to return the documentation / help for a method.
		 *
		 * @param string $methodName The name of the method to retrieve information for.
		 * @return string A string describing the method.
		 **/
		 
		private function getMethodHelp($methodName)
		{
			if (!isset($this->functionMap[$methodName]))
			{
				return false;
			}
			
			return $this->functionMap[$methodName]['docComment'];
		}
		
		/**
		 * Ask the server to handle the request. This is the method you should call when you're ready to handle the XML-RPC-request, after performing initial setup.
		 **/
		 
		public function handleRequest()
		{
			// Return XML.
			header('Content-Type: text/xml');
			
			try
			{
				if (empty($GLOBALS['HTTP_RAW_POST_DATA']))
				{
					throw new XRPC_Exception('Missing XML-RPC request body.', 4);
				}

				// Respond with the result from dispatching the request.				
				print($this->parseAndDispatchRequest($GLOBALS['HTTP_RAW_POST_DATA']));
			}
			catch (XRPC_Exception $e)
			{
				// Or if something goes wrong, return the XML-RPC error document.
				print($e->getXML());
			}
		}
		
		/**
		 * Parse the XML-RPC document using SimpleXML, validate the inputs and call the function.
		 * 
		 * @param string $input The XML-RPC request.
		 * @return string An XML-RPC compatible result document.
		 **/
		
		private function parseAndDispatchRequest($input)
		{
			// Load the XML-document into SimpleXML.
			$root = new SimpleXMLElement($input);
			
			if (!$root->methodName)
			{
				throw new XRPC_Exception('Missing methodName', 2);
			}
			
			// Fetch methodName
			$methodName = (string) $root->methodName;
			
			// Check that the function is a valid, exported function.
			if (!isset($this->functionMap[$methodName]))
			{
				throw new XRPC_Exception('Invalid methodName.', 1);
			}
			
			// The parameters submitted in the request
			$params = array();
			
			foreach ($root->params->param as $param)
			{
				if (!isset($param->value))
				{
					throw new XRPC_Exception('Missing value in <param>', 3);
				}
			
				$paramValue = $param->value;
				
				// Convert the parameter to a PHP compatible datatype
				$params[] = $this->getPHPValue($paramValue);
			}
			
			// Do the magic by calling the requested function / method
			$result = call_user_func_array($this->functionMap[$methodName]['internalFunction'], $params);
			
			// Format the Response as an XML-RPC compatible document.
			return $this->createResponse($result);
		}
		
		/**
		 * Convert an SimpleXML Object from a XML-RPC request to a PHP datatype.
		 *
		 * @param SimpleXMLElement $simpleXMLObj The object containing the XML-RPC value.
		 * @return mixed Return the XML-RPC value converted to a native PHP datatype.
		 **/
		
		private function getPHPValue($simpleXMLObj)
		{
			$first = true;
			$value = false;
			
			foreach ($simpleXMLObj->children() as $value)
			{
				// Check that we don't have more than one datatype in this &lt;value&gt; tag.
				if (!$first)
				{
					throw new XRPC_Exception('Invalid number of containers in one <value>.', 6);
				}
				
				// Convert the value to a string to extract it from SimpleXML
				$str_value = (string) $value;
				
				// Check what kind of XML-RPC value we're dealing with
				switch($value->getName())
				{
					// 32-bit integer
					case 'int':
					case 'i4':
						$value = (int) $str_value;
						break;
					
					// boolean (0/1 in XML-RPC)
					case 'boolean':
						if ($str_value)
						{
							$value = true;
						}
						else
						{
							$value = false;
						}
						
						break;
					
					// Just return the string if it's a string.
					case 'string':
						$value = $str_value;
						break;
					
					// Just double, as XML-RPC don't know floats..
					case 'double':
						$value = (double) $str_value;
						break;
					
					// A dateTime.iso8601 field.
					case 'dateTime.iso8601':
						// If we should create DateTime-objects
						if ($this->returnDateTimeObject)
						{
							$value = date_create($str_value);
						}
						else
						{
							// use strtotime() to validate the given DATE-string. DATE_ISO8601 was introduced in PHP 5.1.
							$value = date(DATE_ISO8601, strtotime($str_value));
						}
						break;
					
					// decode base64 if we receive encoded data.
					case 'base64':
						$value = base64_decode($str_value);
						break;
						
					// Should not happen for valid requests, but generate an error if not valid.
					default:
						throw new XRPC_Exception('Unknown value-type.', 6);
						break;
				}
				
				// We're no longer on the first datatype in this value.
				$first = false;
			}
			
			// return the native PHP value.
			return $value;
		}
		
		/**
		 * Create the XML-RPC Response Document
		 *
		 * @param mixed $variable The returned value from the function that was called.
		 * @return string The XML-RPC Response Document
		 **/
		
		private function createResponse($variable)
		{
			return '<methodResponse><params><param>' . $this->serializeVar($variable) . '</param></params></methodResponse>';
		}
		
		/**
		 * Serialize a variable type from native PHP types to XML-RPC compatible types
		 *
		 * @param mixed $var The input variable.
		 * @return string The variable converted to an XML-RPC based string.
		 **/
		 
		private function serializeVar($var)
		{
			if (is_array($var))
			{
				// array or struct, do recursive parsing..

				// check if we have an indexed array				
				// this seems to be the only proper way to do this in PHP..
				$indexed = true;
				$array_size = count($var);
				
				for ($i = 0; $i < $array_size; $i++)
				{
					if (!isset($var[$i]))
					{
						// stop the traversal asap (this probably happens on the first value for structs anyway)
						$indexed = false;
						break;
					}
				}

				$return = '';
				
				// if the array is indexed, return an XML-RPC array instead of a struct.
				if ($indexed)
				{
					$return = '<array><data>';
					
					foreach($var as $index => $value)
					{
						// serialize each value in the array..
						$return .= $this->serializeVar($value);
					}
					
					$return .= '</data></array>';
				}
				else
				{
					// we have a struct..
					$return = '<struct>';
					
					foreach($var as $name => $value)
					{
						// serialize each element in the struct.
						$return .= '<member><name>' . escape_xmlrpc_string($name) . '</name>' . $this->serializeVar($value) . '</member>';
					}
					
					$return .= '</struct>';
				}

				return '<value>' . $return . '</value>';
			}
			else
			{
				// primitive data structure
				$type = '';
				
				// check if we're dealing with an integer
				if (is_int($var))
				{
					$type = 'int';
				}
				// boolean value?
				else if (is_bool($var))
				{
					$type = 'boolean';
					
					if($var)
					{
						$var = 1;
					}
					else
					{
						$var = 0;
					}
				}
				// double or float? (XML-RPC only has float, so we apply float to both these)
				else if (is_double($var) || is_float($var))
				{
					$type = 'double';
				}
				// since PHP know nothing about 'base64' or 'datetime', we'll have to deal with them manually
				else 
				{
					// pattern for datetime described in XML-RPC document: 19980717T14:08:55
					// pattern described in http://www.w3.org/TR/NOTE-datetime 1998-07-17T14:08:55.xx+01:00
					// iso8601 uses "Z" to mean "UTC" as a timezone descriptor
					// this should catch most formats, including YYYYMM-DD
					if ($this->detectDateTime && preg_match('/^[0-9]{4}-?[0-9]{2}-?[0-9]{2}T[0-9]{2}:[0-9]{2}:[0-9]{2}(\.[0-9]{2})?(Z|\+[0-9]{2}:[0-9]{2})?$/', $var))
					{
						$type = 'dateTime.iso8601';
					}
					// we could attempt to detect binary values here and use base64..
					else
					{
						$base64 = false;
						
						for ($i = 0; $i < strlen($var); $i++)
						{
							// if not ascii..
							if (ord($var[$i]) > 127)
							{
								$base64 = true;
								break;
							}
						}
						
						if ($base64)
						{
							$type = 'base64';
							$var = base64_encode($var);
						}
						else
						{
							$type = 'string';
						}
					}
				}
				
				// return the XML-RPC encoded value and type
				return '<value><' . $type . '>' . escape_xmlrpc_string($var) . '</' . $type . '></value>';
			}
		}
	}
?>
