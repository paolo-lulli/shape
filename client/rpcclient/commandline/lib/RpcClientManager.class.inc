<?php
	require_once("lib/xmlrpc.inc");

class RpcClientManager
{
/*
$parameters = array(    php_xmlrpc_encode("a"), 
			php_xmlrpc_encode("b"), 
			php_xmlrpc_encode("c") 
			);
$method = 'test.connection';
*/

public function launchService($method, $parameters){
$rpc_proxy_page ="/hb.lulli.net/gw/rpc.php";
$rpc_proxy_host ="localhost";
$rpc_proxy_port ="80";
/*
$rpc_proxy_page ="/hackbook/www/gw/rpc.php";
$rpc_proxy_host ="dev.lulli.net";
$rpc_proxy_port ="80";
*/

		$f=new xmlrpcmsg($method, $parameters);
		$c=new xmlrpc_client($rpc_proxy_page, $rpc_proxy_host, $rpc_proxy_port);
		/////////////////////////////
//		$c->setDebug(1);
		///////////////////////////
		$r=&$c->send($f);
		if(!$r->faultCode())
		{
			$v=$r->value();
//			print $v->scalarval(); // only for debug ...
		}
		else
		{
			print "Error " . $r->faultCode() . " Reason: '" . $r->faultString() ;
		}

	return php_xmlrpc_decode($v);
}
}
?>
