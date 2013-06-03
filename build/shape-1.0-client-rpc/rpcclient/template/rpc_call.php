<?php
	include("../../../www/settings.inc");
	include(ROOT."/kernel/RpcClientManager.class.inc");

$parameters =    array(    
			php_xmlrpc_encode("admin"), 
                        php_xmlrpc_encode(sha1("admin")) 
                      );
$method = 'auth.login';

	$mgr = new RpcClientManager;
	$mgr->launchService($method, $parameters);


?>
