<?php

//require_once ('../conf/backend.inc');
require_once ("LogManager.class.inc");
require_once ("GenericDao.class.inc");
require_once ("DBManager.class.inc");


class RoleDao extends GenericDao
{
//var tableName;


public function getObjectById($id){
}

public function insertPolicy($id_resource, $id_role, $perms, $description){
/*
  <ID_Resource>varchar(36)</ID_Resource>
    <ID_Role>varchar(36)</ID_Role>
    <description>varchar(256)</description>

    <perms>varchar(12)</perms>
*/

}


public function getRoles($login_id){

$log_manager = new LogManager();
$db = DBManager::getInstance();
$db = $this->getConnection();

$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";

$query = sprintf("select r.name as role from  $accountTable a 
join $userTable u on u.ID = a.ID_User
join $usergroupTable g on g.ID = a.ID_Usergroup
join $roleTable r on  r.ID = a.ID_Role
where u.ID ='%s'",
    mysql_real_escape_string($login_id));
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getRoles()");
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



public function getRoleId($role_name){


$log_manager = new LogManager();
$db = DBManager::getInstance();
$db = $this->getConnection();

$roleTable =DBMANAGER::$tablesPrefix."Role";
$query = sprintf("select ID as rid from $roleTable where name ='%s'", $role_name);
// Perform Query
$results = $db->query($query);
$log_manager->query($query, "getRoles()");
//$row = $results->fetchArray();
$row = $results->fetch(PDO::FETCH_ASSOC);
$count=0;
if (  strcmp($row["rid"], "0") ){
	$role_id = $row["rid"];
}
return $role_id;
}

public function createRole($name, $description){
	$roleTable =DBMANAGER::$tablesPrefix."Role";
     	$table = $roleTable;
        $actual_date = date("Y-m-d H:i:s");
        $guidGenerator = new GuidGenerator;
        $ID = $guidGenerator->generate();
        $qm = new QueryManager;
        $fields = array( 'ID','created', 'name', 'updated','description');
        $values = array( $ID,$actual_date, $name, $actual_date, $description);
        try{
                $qm->insertTable($table,$fields,$values);
        } catch(Exception $e){
                $results = $e->getMessage();
        }
return $ID;


}
public function deleteRole($role_id){
 $db = DBManager::getInstance();
        $logManager = new LogManager;
	$roleTable =DBMANAGER::$tablesPrefix."Role";
        $query = "DELETE from $roleTable where ID =\'". $role_id .'\'';
        $logManager->query($query, "delete() Role");
        $results = $db->exec($query);
        return $results; //is an int
}

public function deleteRoleByName($role_name){
 	$db = DBManager::getInstance();
        $logManager = new LogManager;
	$roleTable =DBMANAGER::$tablesPrefix."Role";
        $query = "DELETE from $roleTable where name =\'". $role_name .'\'';
        $logManager->query($query, "delete() Role");
        $results = $db->exec($query);
        return $results; //is an int
}


}
?>
