<?php
	include("../../../www/settings.inc");
	include(ROOT."/kernel/RpcClientManager.class.inc");

function performLogin(){
$method = 'auth.login';
$parameters =    array(    
			php_xmlrpc_encode("admin"), 
                        php_xmlrpc_encode(sha1("admin")) 
                      );

	$mgr = new RpcClientManager;
	$userid = $mgr->launchService($method, $parameters);
	return $userid;
}



//$userid = php_xmlrpc_decode(performLogin());
$userid = performLogin();
echo "ID User =[" . $userid . "]";

?>
