<?php
	require_once("xmlrpc.inc");
	require_once("RpcClientManager.class.inc");

class RpcClient
{

function performLogin($username, $password){
$method = 'auth.login';
$parameters =    array(
                        php_xmlrpc_encode($username),
                        php_xmlrpc_encode(sha1($password))
                      );

        $mgr = new RpcClientManager;
        $userid = $mgr->launchService($method, $parameters);
        return $userid;
}

function getRegistry($userid){
$parameters = array(
                    php_xmlrpc_encode($userid)
                   );
$method = 'registry.get';

        $mgr = new RpcClientManager;
        $registry = $mgr->launchService($method, $parameters);
	return $registry;
}

}
?>
