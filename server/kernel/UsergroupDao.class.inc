<?php

require_once 'LogManager.class.inc';
require_once 'DBManager.class.inc';
require_once 'GenericDao.class.inc';

class UsergroupDao extends GenericDao
{

public function getNickname($login_id){

$log_manager = new LogManager;


$user_id = "0";
// $pass_hash = sha1($password)

$db = DBManager::getInstance();

$query = sprintf("select nickname from User
where ID ='%s'" , 
    mysql_real_escape_string($login_id));
//echo $query;

// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getNickname()");
//$row = $results->fetchArray();
$row = $results->fetch(PDO::FETCH_ASSOC);
if (  strcmp($row["nickname"], "0") ){
	$user_id = $row["nickname"];
}
return $user_id;
}

public function getRoles($login_id){

$log_manager = new LogManager;
$db = DBManager::getInstance();

$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";

$query = sprintf("select r.name as role from   $accountTable a 
join $userTable u on u.ID = a.ID_User
join $usergroupTable g on g.ID = a.ID_Usergroup
join $roleTable r on  r.ID = a.ID_Role
where u.ID ='%s'",
    mysql_real_escape_string($login_id));
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getRoles()");
//$row = $results->fetchArray();
$row = $results->fetch(PDO::FETCH_ASSOC);
$count=0;
$roles = array();
if (  strcmp($row["role"], "0") ){
	$role_id = $row["role"];
	$roles [$count] = "$role_id";
	$count++;	
}
return $roles;
}


public function getGroups($login_id){

$log_manager = new LogManager;
$db = DBManager::getInstance();

$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";

$query = sprintf("select g.name as usergroup from   $accountTable a 
join $userTable u on u.ID = a.ID_User
join $usergroupTable g on g.ID = a.ID_Usergroup
join $roleTable r on  r.ID = a.ID_Role
where u.ID ='%s'",
    mysql_real_escape_string($login_id));
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getGroups()");
//$row = $results->fetchArray();
$row = $results->fetch(PDO::FETCH_ASSOC);
$count=0;
$roles = array();
if (  strcmp($row["usergroup"], "0") ){
	$role_id = $row["usergroup"];
	$groups [$count] = "$role_id";
	$count++;	
}
return $groups;
}

public function getGroupId($groupname){

$log_manager = new LogManager;
$db = DBManager::getInstance();

$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";
$query = sprintf("select g.ID as id from $usergroupTable g where g.name ='%s'", $groupname);
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getGroupId()");
$row = $results->fetch(PDO::FETCH_ASSOC);
$count=0;
var_dump($row);
if (  strcmp($row["id"], "0") ){
        $group_id = $row["id"];
        $count++;
}
return $group_id;
}


}
?>
