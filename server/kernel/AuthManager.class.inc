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
	$user_id = "0";
// $pass_hash = sha1($password)
	 $db = DBManager::getInstance();
	$userTable =DBMANAGER::$tablesPrefix."User";

	$query = sprintf("select ID as uid from $userTable 
where nickname ='%s' 
and password ='%s'",
    $login,
    $pass_hash);

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "login()");
	$row = $results->fetch(PDO::FETCH_ASSOC); 

	if (  strcmp($row["uid"], "0") ){
		$user_id = $row["uid"];
	}
return $user_id;
}

public function getUserIdByToken($token){
	$log_manager = new LogManager;
	$user_id = "0";
	$db = DBManager::getInstance();
	$userTable =DBMANAGER::$tablesPrefix."User";
	$roleTable =DBMANAGER::$tablesPrefix."Role";
	$accountTable =DBMANAGER::$tablesPrefix."Account";
	$query = sprintf("select u.ID as uid from $userTable u, $accountTable a  where u.ID = a.ID_User and a.active='1'  and a.token ='%s'", $token);

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "login()");
	$row = $results->fetch(PDO::FETCH_ASSOC); 
	if (  strcmp($row["uid"], "0") ){
		$user_id = $row["uid"];
	}
return $user_id;
}

public function getRoleIdByToken($token){
	$log_manager = new LogManager;
	$userTable =DBMANAGER::$tablesPrefix."User";
	$roleTable =DBMANAGER::$tablesPrefix."Role";
	$accountTable =DBMANAGER::$tablesPrefix."Account";
	$role_id = "0";
	$db = DBManager::getInstance();

	$query = sprintf("select r.ID as id from $roleTable r, $accountTable a  where r.ID = a.ID_Role and a.active='1'  and a.token ='%s'", $token);

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "login()");
	$row = $results->fetch(PDO::FETCH_ASSOC); 
	if (  strcmp($row["id"], "0") ){
		$role_id = $row["id"];
	}
return $role_id;
}

public function getToken($login, $pass_hash){
	$log_manager = new LogManager;
	$user_id = "0";
// $pass_hash = sha1($password)
	 $db = DBManager::getInstance();
	$userTable =DBMANAGER::$tablesPrefix."User";
        $accountTable =DBMANAGER::$tablesPrefix."Account";
	$query = sprintf("select token from $userTable u, $accountTable a  where u.id = a.ID_User and a.active='1'
where u.nickname ='%s' 
and u.password ='%s'",
    $login,
    $pass_hash);
//echo $query;

// Perform Query
	$results = $db->query($query);
	$log_manager->query($query, "getToken()");
	$row = $results->fetch(PDO::FETCH_ASSOC); 

	if (  strcmp($row["token"], "0") ){
		$token = $row["token"];
	}
return $token;
}

function authResourceByToken($token, $resource_id){
        $am = new AuthManager();
        $user_id = $am->getUserIdByToken($token);
        $role_id = $am->getRoleIdByToken($token);
        $result = $am->authResource($user_id, $role_id, $resource_id);
        return $result;
}



function authResource($user_id, $role_id, $resource_id){

/*
$user_id =$_REQUEST['USER'];
$role_id =$_REQUEST['ROLE'];
$resource_id =$_REQUEST['RESOURCE'];
*/

$db = DBManager::getInstance();
//$db = new SQLite3(DB_FILE);

$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";
$policyTable =DBMANAGER::$tablesPrefix."Policy";

/*
$sql ="select count(*) as authorized from $accountTable a
join $userTable u on u.ID = a.ID_User
join $roleTable r on  r.ID = a.ID_Role
join $usergroupTable g on g.ID = a.ID_Usergroup
join $policyTable p on p.ID_Role = r.ID
where u.ID = '$user_id'
and   r.ID = '$role_id'
and   p.ID_Resource = '$resource_id'";
*/
$query = sprintf("select count(*) as authorized from $accountTable a
join $userTable u on u.ID = a.ID_User
join $roleTable r on  r.ID = a.ID_Role
join $usergroupTable g on g.ID = a.ID_Usergroup
join $policyTable p on p.ID_Role = r.ID
where u.ID = '%s'
and   r.ID = '%s'
and   p.ID_Resource = '%s'",
    $user_id,
    $role_id,
    $resource_id);
//echo "SQL:[".$sql."]";

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
