<?php
require_once('./web.inc');

error_reporting(E_ALL);
ini_set('display_errors', 'On');

require_once(BACKEND_DIR.'/kernel/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel/RoleDao.class.inc');

// Gruppi esistenti: group-users, group-wheel

$cm = new ConfManager;

$cm->createRole('role-xxx-admin', 'role for xxx admin');
$cm->createRole('role-xxx-user', 'role for generic xxx user');

$sha1_pass=sha1("paolo");
$userid_paolo = $cm->registerUser( "paolo", 	"lulli", 	"paolo.lulli", 		$sha1_pass, 	"plulli@gmail.com");
$ac_id_paolo = $cm->createAccount($userid_paolo, "group-wheel", "role-xxx-admin");
$cm->activateAccount($ac_id_paolo);

//

//$cm->removeResourceFromRole('draft', 'b-role-test');
$cm->addResourceToRole("Shape-TemplateResource", 	'role-xxx-admin');

?>
