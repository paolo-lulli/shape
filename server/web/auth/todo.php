
<?php
require_once('../web.inc');

require_once(BACKEND_DIR.'/kernel'.'/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/RoleDao.class.inc');



$cm = new ConfManager;



$userid = $cm->registerUser( "paolo", "lulli", "blacksheep", "paolo", "plulli@gmail.com");
//$cm->createAccount($userid, $roleid, $groupid)
$cm->createAccount($userid, "group-users", "role-web-admin");
//Sono ruoli e gruppi già esistenti
//$cm->deactivateAccount($account_id);
$cm->activateAccount($account_id);
//

//$cm->createRole('role-test', 'a fake role to test the insert');

//$cm->removeResourceFromRole('draft', 'b-role-test');

$cm->createRole('utente-generico', 'a fake role to test the insert');


//$cm->addResourceToRole($resName, $roleName);

$cm->createRole('article-role', 'role for articles only');
$cm->addResourceToRole("Articolo", 'article-role');

?>
			
		
	
