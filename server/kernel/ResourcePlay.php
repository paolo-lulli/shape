<?php
require_once("../conf/backend.inc");
require_once(BACKEND_DIR."/kernel/ResourceProxy.class.inc");
require_once(BACKEND_DIR."/kernel/UserDAO.class.inc");
require_once(BACKEND_DIR."/kernel/Registry.class.inc");

$mgr = new AuthManager;
$username="admin";
$password="admin";
$userid = $mgr->login($username, sha1($password));

$userdo = new UserDAO;
$nick = $userdo->getNickname($userid);
$registry = new Registry;
$reg = $registry->init($userid);
//$registry = $registry->setRoleByName($reg, "commandline");
$reg["$userid"]['role'] = "commandline";
var_dump($reg);
$resProxy = new ResourceProxy;

$resource = $resProxy->getResource($userid, $reg[$user_id]['role'] , "Test");
if ( NULL != $resource ) {
	$resource->execute();
} else {
	echo "Resource is NULL";
}
?>
