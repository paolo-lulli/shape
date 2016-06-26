<?php

require_once 'LogManager.class.inc';
require_once 'DBManager.class.inc';

class UserDAO
{

public function getNickname($login_id){

$log_manager = new LogManager;


$user_id = "0";
// $pass_hash = sha1($password)

$db = DBManager::getInstance();

$userTable =DBMANAGER::$tablesPrefix."User"; 
$query = sprintf("select nickname from ".$userTable." where ID ='%s'" , 
    $login_id);
//echo $query;

// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getNickname()");
///$row = $results->fetchArray();
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
    $login_id);
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getRoles()");

////////////$row = $results->fetchArray();
$count=0;
$roles = array();
//if (  strcmp($row["ROLE"], "0") ){
//while($row = $results->fetchArray()){
while($row = $results->fetch(PDO::FETCH_ASSOC)){
	$role_id = $row["role"];
	//$roles [$count] = "$role_id";
	$roles [] = "$role_id";
	$count++;	
//}
}
return $roles;
}


public function getGroups($login_id){

$groups=array();
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
    $login_id);
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getGroups()");
///////////$row = $results->fetchArray();
$count=0;
$roles = array();
while($row = $results->fetch(PDO::FETCH_ASSOC)){
//if (  strcmp($row["USERGROUP"], "0") ){
	$role_id = $row["usergroup"];
	$groups [$count] = "$role_id";
	$count++;	
//}
}
return $groups;
}


}
?>
