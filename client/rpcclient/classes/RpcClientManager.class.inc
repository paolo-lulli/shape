<?php
	//require_once("xmlrpc.inc");
 	require_once(CLIENT_DIR."/lib/xmlrpc.inc");


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

	$rpc_proxy_page = RPCPROXY_GATEWAY;
	$rpc_proxy_host = RPCPROXY_HOST;
	$rpc_proxy_port = RPCPROXY_PORT;
	$rpc_proxy_user = RPCPROXY_USER;
	$rpc_proxy_pass = RPCPROXY_PASS;

	/*
	$xmlrpcVal = NULL;
	foreach($parameters as $pam) {
		$xmlrpcVal->addParam((new xmlrpcval($pam, "string")));
	}
	*/
		/* DOC says:
			$msg=new xmlrpcmsg("examples.getStateName", array(new xmlrpcval(23, "int")));
		*/
		$f=new xmlrpcmsg($method, $parameters);
		//$f=new xmlrpcmsg($method, $xmlrpcVal);
		$c=new xmlrpc_client($rpc_proxy_page, $rpc_proxy_host, $rpc_proxy_port);
		// TODO ---- $c->setCredentials($rpc_proxy_user, $rpc_proxy_pass);
		/*
		
		http://www.koders.com/php/fidACB33FB0217545091E7E422F5B6E054CA49BBB03.aspx?s=%22Edd+Dumbill%22#L7


		$c->setCredentials($u, $p)
		{
			$this->username = $u;
			$this->password = $p;
		}

		$c->setCertificate($cert, $certpass)
		{
			$this->cert     = $cert;
			$this->certpass = $certpass;
		}

		*/

		/////////////////////////////
		//$c->setDebug(1);
		///////////////////////////
		$r=&$c->send($f);
		if(!$r->faultCode())
		{
			$v=$r->value();
			print $v->scalarval(); // only for debug ...
		}
		else
		{
			print "Error " . $r->faultCode() . " Reason: '" . $r->faultString() ;
		}
	return php_xmlrpc_decode($v);
}
}
?>
