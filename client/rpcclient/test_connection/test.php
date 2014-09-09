<?php
	include("xmlrpc.inc");

$parameters = array(    php_xmlrpc_encode("a"), 
			php_xmlrpc_encode("b"), 
			php_xmlrpc_encode("c") 
			);
$method = 'test.connection';
		$f=new xmlrpcmsg($method, $parameters);
		$c=new xmlrpc_client("/hb/gw/rpc.php", "localhost", 80);
		//$c->setDebug(1);
		$r=&$c->send($f);
		if(!$r->faultCode())
		{
			$v=$r->value();
			print $v->scalarval();
		}
		else
		{
			print "Error " . $r->faultCode() . " Reason: '" . $r->faultString() ;
		}

?>
