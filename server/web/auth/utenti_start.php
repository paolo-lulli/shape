<?php
require_once('../web.inc');

require_once(BACKEND_DIR.'/kernel/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel/RoleDao.class.inc');


$cm = new ConfManager;

$cm->createRole('role-web-admin', 'Administrator Role');

$cm->createResource('Profile', 'Profile');
$cm->createResource('Part', 'Part');
$cm->createResource('Order', 'Order');
$cm->createResource('Shipping', 'Shipping');
$cm->createResource('Quote', 'Quote');
$cm->createResource('Product', 'Product');
$cm->createResource('Contact', 'Contact');

$cm->addResourceToRole("Profile",       'role-web-admin');
$cm->addResourceToRole("Part",          'role-web-admin');
$cm->addResourceToRole("Order",         'role-web-admin');
$cm->addResourceToRole("Shipping",      'role-web-admin');
$cm->addResourceToRole("Quote",         'role-web-admin');
$cm->addResourceToRole("Product",       'role-web-admin');
$cm->addResourceToRole("Contact",       'role-web-admin');


$password_paolo	="paolo";
$password_tzn	="tiziano";
$password_m	="michaela";

$h_password_paolo	=	sha1($password_paolo);
$h_password_tzn		=	sha1($password_tzn);
$h_password_m		=	sha1($password_m);

$userid_paolo = $cm->registerUser( "paolo", "lulli", "paolo.lulli", $h_password_paolo, "plulli@gmail.com");
$userid_tzn   = $cm->registerUser( "tiziano", "albrizio", "tiziano.albrizio", $h_password_tzn, "tiziano.albrizio@libero.it");
$userid_mic   = $cm->registerUser( "micaela", "franceschini", "micaela.franceschini", $h_password_m, "mf7055@gmail.com");

//$cm->createAccount($userid, $roleid, $groupid)
$ac_id_paolo = $cm->createAccount($userid_paolo, "group-wheel", "role-web-admin");
$ac_id_tzn   = $cm->createAccount($userid_tzn,   "group-wheel", "role-web-admin");
$ac_id_mic   = $cm->createAccount($userid_mic,   "group-wheel", "role-web-admin");
//Sono ruoli e gruppi già esistenti
//$cm->deactivateAccount($account_id);
$cm->activateAccount($ac_id_paolo);
$cm->activateAccount($ac_id_tzn);
$cm->activateAccount($ac_id_mic);

//$cm->createRole('role-test', 'a fake role to test the insert');
//$cm->removeResourceFromRole('draft', 'b-role-test');
//$cm->addResourceToRole($resName, $roleName);

?>
			
		
	
