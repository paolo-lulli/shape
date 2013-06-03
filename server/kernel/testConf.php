<?php
require_once('../conf/backend.inc');

require_once(BACKEND_DIR.'/kernel'.'/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/RoleDao.class.inc');


/*
$ugdao = new UsergroupDao;
$groupid = $ugdao->getGroupId("group-users");
echo "group ID: " .$group_id . "\n";

$roledao = new RoleDao;
$roleid = $roledao->getRoleId("role-web-admin");
echo "role ID: " .$role_id . "\n";
*/

$cm = new ConfManager;
/*
$userid = $cm->registerUser( "paolo", "lulli", "blacksheep", "paolo", "plulli@gmail.com");
//$cm->createAccount($userid, $roleid, $groupid)
$cm->createAccount($userid, "group-users", "role-web-admin");
//Sono ruoli e gruppi già esistenti
$cm->deactivateAccount($account_id);
$cm->activateAccount($account_id);
*/

//$cm->createRole('role-test', 'a fake role to test the insert');

$cm->removeResourceFromRole('draft', 'b-role-test');


?>
