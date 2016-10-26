<?php
header('Cache-Control: no-cache, must-revalidate');
header('Expires: Mon, 26 Jul 1997 05:00:00 GMT');
header('Content-type: application/json');

$resource_id = "draft";
include_once("../web.inc");
include_once(WWWDIR."/xhr-auth/auth_resource.php");
include_once(BACKEND_DIR."/kernel/RoleDao.class.inc");

$id_user = $_SESSION['USER'];
$selectedRole = "";
if (! empty ($_REQUEST['role'])){
        $selectedRole = $_REQUEST['role'];
}

	$roles = $registry[$id_user]['roles'];
	if (in_array($selectedRole, $roles)){
		//print "Role OK";
		$roleDao = new RoleDao();
		$role_id = $roleDao->getRoleId($selectedRole);
		$registry[$id_user]['id_role'] = $role_id;
		$registry[$id_user]['role'] = $selectedRole;
		$_SESSION['registry'] = $registry;
		//print "role_id==" . $role_id;
	} else {
		print "";
	}
	//var_dump($registry);
	print "xhr_selectRole(".json_encode($registry).");";
?>

