<?php
require_once('../conf/backend.inc');

require_once(BACKEND_DIR.'/kernel'.'/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/RoleDao.class.inc');


/*
	The USER register
*/


$cm = new ConfManager;

$password = sha1("paolo");
$userid = $cm->registerUser( "paolo", "lulli", "blacksheep", $password, "plulli@gmail.com");
//$cm->createAccount($userid, $roleid, $groupid)
$account_id = $cm->createAccount($userid, "group-users", "role-web-admin");
//Sono ruoli e gruppi già esistenti
$cm->deactivateAccount($account_id);
$cm->activateAccount($account_id);


?>
