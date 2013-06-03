<?php

//require_once 'Log.php';
require_once (BACKEND_DIR ."/conf/backend.inc");
require_once (BACKEND_DIR ."/kernel/LogManager.class.inc");
require_once (BACKEND_DIR ."/kernel/DBManager.class.inc");

class AuthManager
{
//private $log ;

/*

ID_User login(username, password)

*/

public function login($login, $pass_hash){
	$log_manager = new LogManager;
	//$log_manager->debug("aaaaaaaaaaaaa", "login()");
	$user_id = "0";
// $pass_hash = sha1($password)
	 $db = DBManager::getInstance();

	$query = sprintf("select ID from User
where nickname ='%s' 
and password ='%s'",
    $login,
    $pass_hash);
//echo $query;

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "login()");
////////////////////////////$row = $results->fetchArray();
	$row = $results->fetch(PDO::FETCH_ASSOC); 

	if (  strcmp($row["ID"], "0") ){
		$user_id = $row["ID"];
	}
return $user_id;
}

public function getUserIdByToken($token){
	$log_manager = new LogManager;
	//$log_manager->debug("aaaaaaaaaaaaa", "login()");
	$user_id = "0";
	$db = DBManager::getInstance();

	$query = sprintf("select ID from User where token ='%s'", $token);
//echo $query;

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "login()");
////////////////////////////$row = $results->fetchArray();
	$row = $results->fetch(PDO::FETCH_ASSOC); 

	if (  strcmp($row["ID"], "0") ){
		$user_id = $row["ID"];
	}
return $user_id;
}

public function getToken($login, $pass_hash){
	$log_manager = new LogManager;
	//$log_manager->debug("aaaaaaaaaaaaa", "login()");
	$user_id = "0";
// $pass_hash = sha1($password)
	 $db = DBManager::getInstance();

	$query = sprintf("select token from User
where nickname ='%s' 
and password ='%s'",
    $login,
    $pass_hash);
//echo $query;

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "getToken()");
////////////////////////////$row = $results->fetchArray();
	$row = $results->fetch(PDO::FETCH_ASSOC); 

	if (  strcmp($row["token"], "0") ){
		$token = $row["token"];
	}
return $token;
}



function authResource($user_id, $role_id, $resource_id){

/*
$user_id =$_REQUEST['USER'];
$role_id =$_REQUEST['ROLE'];
$resource_id =$_REQUEST['RESOURCE'];
*/

$db = DBManager::getInstance();
//$db = new SQLite3(DB_FILE);

$query = sprintf("select count(*) as authorized from Account a
join User u on u.ID = a.ID_User
join Usergroup g on g.ID = a.ID_Usergroup
join Role r on  r.ID = a.ID_Role
join Policy p on p.ID_Role = r.ID
where u.ID = '%s'
and   r.ID = '%s'
and   p.ID_Resource = '%s'",
    $user_id,
    $role_id,
    $resource_id);
//echo $query;

// Perform Query
$results = $db->query($query);

//$row = $results->fetchArray();
$row = $results->fetch(PDO::FETCH_ASSOC); 
    return $row["authorized"];
}

// userRegistration() - users register themselves, an entry is created in User and Usergroup
// accountCreation()  - An account is created for the existing user in User
// accountActivation()/accountDeactivation()- NOT MANDATORY: the account is (de)activated 
// rolesManagement() creation of Roles
// resourcesInstallation - installation of new Resources
// policyManagement() Resources are given to existing Roles


}
?>
