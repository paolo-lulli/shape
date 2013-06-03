<?php
	//require_once("../conf/rpc.inc");
	require_once(CLIENT_DIR."/lib/xmlrpc.inc");
	require_once(CLIENT_DIR."/classes/RpcClientManager.class.inc");

class TestRpcClient 
{

function testConnection(){
	$method = 'test.connection';
	$parameters =    array();
        $mgr = new RpcClientManager;
        $retValue = 0;
	try{
        	$retValue = $mgr->launchService($method, $parameters);
	} catch(Exception $e) {
		$retValue = $e->getMessage();
	}
        return $retValue;

}

function testParameters($param){
	$method = 'test.parameters';
	$parameters =    array();
        $mgr = new RpcClientManager;
	$parameters =  array(
                        php_xmlrpc_encode($param)
			);
        $retValue = 0;
	try{
        	$retValue = $mgr->launchService($method, $parameters);
	} catch(Exception $e) {
		$retValue = $e->getMessage();
	}
        return $retValue;
}



}
?>
