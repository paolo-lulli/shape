<?
		$resource_id = "draft";

        include_once("../web.inc");
	include_once(WWWDIR."/auth/auth_resource.php");
	include_once(BACKEND_DIR."/kernel/RoleDao.class.inc");

?>


<?php 

$id_user = $_SESSION['USER'];

$selectedRole = "";
if (! empty ($_REQUEST['role'])){
        $selectedRole = $_REQUEST['role'];
}

	echo "You selected ROLE:".$selectedRole;
	$roles = $registry[$id_user]['roles'];
	//var_dump($registry);
	var_dump($roles);
	if (in_array($selectedRole, $roles)){
		print "Role OK";
		$roleDao = new RoleDao();
		$role_id = $roleDao->getRoleId($selectedRole);
		$registry[$id_user]['id_role'] = $role_id;
		$registry[$id_user]['role'] = $selectedRole;
		$_SESSION['registry'] = $registry;
		print "role_id==" . $role_id;
	} else {
		print "Role KO";
	}

	var_dump($registry);
?>

