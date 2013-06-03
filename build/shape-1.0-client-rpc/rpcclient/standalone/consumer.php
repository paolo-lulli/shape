<?php
	include("./lib/RpcClientManager.class.inc");

$parameters =    array(    
			php_xmlrpc_encode("a"), 
                        php_xmlrpc_encode("b"), 
                        php_xmlrpc_encode("c") 
                      );
$method = 'test.connection';

	$mgr = new RpcClientManager;
	$response = $mgr->launchService($method, $parameters);
	print($response);


?>
