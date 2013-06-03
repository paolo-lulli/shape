<?php
   	include("../../../www/settings.inc");
        include(ROOT."/kernel/RpcClientManager.class.inc");

$userid='9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5';

$method     = 'registry.get';
$parameters = array( 
	   php_xmlrpc_encode('9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5')
);

	$mgr = new RpcClientManager;
	//$ret = php_xmlrpc_decode($mgr->launchService($method, $parameters));
	$registry = $mgr->launchService($method, $parameters);

	$role   = $registry["$userid"]['role'];
	$roles  = $registry[$userid]['roles'];
	$groups = $registry[$userid]['groups'];

//	print_r($ret);
//	print_r($registry);
	print 'Role: ' . $role;
?>
