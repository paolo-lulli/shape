<?php

require_once ("LogManager.class.inc");
require_once ("UserDAO.class.inc");
require_once ("RoleDao.class.inc");

class Registry
{

function init($user_id) {

	$userdao = new UserDAO;
	$registry['USER']  = $user_id;

	/*
		Availables user and groups for the actual user
	*/
	$registry[$user_id]['roles']  = $userdao->getRoles($user_id);
	$registry[$user_id]['groups'] = $userdao->getGroups($user_id);
	/*
	 Role in use for the actual user
	*/
	$registry[$user_id]['role']  = "role-generic";
	$roledao = new RoleDao;
	$id_role = $roledao->getRoleId($registry[$user_id]['role']);
	$registry[$user_id]['id_role']  = $id_role;
	return $registry;
}

public function setRole($registry, $role) {
	$user_id = $registry['USER'];
	$avail_roles = $registry[$user_id]['roles'];  
	if(in_array($role,$avail_roles)){ // If selected role is available for that user
		$registry[$user_id]['role']  = $role;
		$roledao = new RoleDao;
		$id_role = $roledao->getRoleId($role);
		$registry[$user_id]['id_role']  = $id_role;
	}
	return $registry;
}

public function setRoleByName($registry, $role) {
	//registry is a hash of keys
	$roleDao = new RoleDao();
	$user_id = $registry['USER'];
	$avail_roles = $registry[$user_id]['roles'];  
	$roleKey = $roleDao->getRoleId($role);

	if(in_array($roleKey,$avail_roles)){ // If selected role is available for that user
		$registry[$user_id]['role']  = $roleKey;
	}
	return $registry;
}

public function getRole($registry) {
	return $registry[$user_id]['role'];
}

public function getRegistry($user_id) {

$reg = new Registry;
$reg = $reg->init($user_id);
return $reg;
}

}
?>
