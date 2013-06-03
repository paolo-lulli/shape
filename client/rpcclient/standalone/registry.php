<?php
	include("./lib/RpcClientManager.class.inc");

$parameters = array(    
                    php_xmlrpc_encode("9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5")
                   );
$method = 'registry.get';

	$mgr = new RpcClientManager;
	$ret = $mgr->launchService($method, $parameters);
	var_dump($ret);
?>
