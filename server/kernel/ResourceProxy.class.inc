<?php

//require_once 'Log.php';
require_once ('../conf/backend.inc');
require_once 'LogManager.class.inc';
require_once 'AuthManager.class.inc';
require_once 'ResourceManager.class.inc';

class ResourceProxy
{


//public function getResource($res_name, $user_id, $role_id, $resource_id){
public function getResource($user_id, $role_id, $resource_id){

$auth_mgr = new AuthManager;
$is_authorized = $auth_mgr->authResource($user_id, $role_id, $resource_id);

if ($is_authorized){
	$resource_mgr = new ResourceManager;
        $resource = $resource_mgr->getResource($res_name);
}

/*
$resource['setup'] ;
$resource['data'] ;
$resource['display'];

$resource['class'];
*/


return $resource;
}

/*
TODO

public function loadResourceOnDb($res_name){}
public function zipResource($res_name){}
public function saveResourceToFile($res_name){}
public function loadResourceFromDb($res_name){}
*/
}
?>
