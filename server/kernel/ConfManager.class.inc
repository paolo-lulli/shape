<?php

//require_once 'Log.php';
require_once(BACKEND_DIR.'/conf/backend.inc');

require_once(BACKEND_DIR."/kernel/ConfigurationInterface.class.inc");
require_once(BACKEND_DIR."/kernel/LogManager.class.inc");
require_once(BACKEND_DIR."/kernel/DBManager.class.inc");
require_once(BACKEND_DIR."/kernel/QueryManager.class.inc");
require_once(BACKEND_DIR."/kernel/GuidGenerator.class.inc");
require_once(BACKEND_DIR."/kernel/AccountDao.class.inc");
require_once(BACKEND_DIR."/kernel/UsergroupDao.class.inc");
require_once(BACKEND_DIR."/kernel/RoleDao.class.inc");
require_once(BACKEND_DIR."/kernel/PolicyDao.class.inc");

class ConfManager extends ConfigurationInterface
{
/** 
	users register themselves, an entry is created in User and Usergroup
	Returns the ID of the registered User
*/
public function registerUser( $name, $surname, $nickname, $password, $openid ){
$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";

	$table = $userTable;
 	$actual_date = date("Y-m-d H:i:s");
 	$guidGenerator = new GuidGenerator;
    $ID = $guidGenerator->generate();
	$qm = new QueryManager;
	$fields = array("ID","openid", "created", "password", "nickname", "name", "updated", "surname");
	$values = array($ID,  $openid, $actual_date, $password, $nickname, $name, $actual_date, $surname);
    try{
		$qm->insertTable($table,$fields,$values);
    } catch(Exception $e){
    	$results = $e->getMessage();
    }
    return $ID; 
}

public function generateToken( $ID_User ){
$userTable =DBMANAGER::$tablesPrefix."User";
$roleTable =DBMANAGER::$tablesPrefix."Role";
$accountTable =DBMANAGER::$tablesPrefix."Account";
$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";
	//$table = "User";
	$table = $userTable;
 	$actual_date = date("Y-m-d H:i:s");
 	$guidGenerator = new GuidGenerator;
    $token = $guidGenerator->generate();
	$qm = new QueryManager;
	$fields = array("token");
	$values = array($token);
	$where_fields = array("ID");
	$where_values = array($ID_User);
    try{
		$qm-> updateTable($table, $fields, $values, $where_fields, $where_values);
    } catch(Exception $e){
    	$results = $e->getMessage();
    }
    return $token; 
}



/** 
An account is created for the existing user in User
- Any row defines a particular <role> for the user in the <group>
*/
public function createAccount($userid, $group_name, $role_name){
	$ugdao = new UsergroupDao;
	$groupid = $ugdao->getGroupId($group_name);
	print "\ngroupid=".$groupid;
	$roledao = new RoleDao;
	$roleid = $roledao->getRoleId($role_name);
	print "\nroleid=".$roleid;
	$accdao = new AccountDao;
	$idAccount = $accdao->insertAccount($userid, $roleid, $groupid);
	print "\nidAccount=".$idAccount;
	return $idAccount; 
}



// accountActivation()/accountDeactivation()- NOT MANDATORY: the account is (de)activated 
public function activateAccount($account_id){
        $db = DBManager::getInstance();
        $logManager = new LogManager;
	$accountTable =DBMANAGER::$tablesPrefix."Account";
	$query = "UPDATE $accountTable set active = 1 where ID ='". $account_id .'\'';
        $logManager->query($query, "update() Account");
        $results = $db->exec($query);
        return $results; //is an int
}

public function deactivateAccount($account_id){
        $db = DBManager::getInstance();
        $logManager = new LogManager;
	$accountTable =DBMANAGER::$tablesPrefix."Account";
	$query = "UPDATE $accountTable set active = 0 where ID ='". $account_id .'\'';
        $logManager->query($query, "update() Account");
        $results = $db->exec($query);
        return $results; //is an int
}

/** TODO even if roles exists already */
// rolesManagement() creation of Roles
public function createRole($name, $description){
	$roleDao = new RoleDao;
	$roleid = $roleDao->createRole($name, $description);
	return $roleid;
}
public function deleteRole($roleName){
	$roleDao = new RoleDao;
        $result = $roleDao->deleteRoleByName($roleName);
        return $result;
}

// resourcesInstallation - installation of new Resources
//deprecated
public function installResource($resName){
	$resManager = new ResourceManager;
	$retval = $resManager->installResource($resName);
	return $retval;
}

public function deleteResource($resName){
	$resourceTable =DBMANAGER::$tablesPrefix."Resource";
       $db = DBManager::getInstance();
        $logManager = new LogManager;
        $query = "DELETE FROM $resourceTable where name =\'". $resName .'\' ';
        $logManager->query($query, "delete() Policy");
        $results = $db->exec($query);
        return $results; //is an int
}

// policyManagement() Resources are given to existing Roles
public function addResourceToRole($resName, $roleName){
	$policyDao = new PolicyDao;
	$policyDao ->assignResourceToRole($resName, $roleName);
}

public function removeResourceFromRole($resName, $roleName){
   	$db = DBManager::getInstance();
        $logManager = new LogManager;
	$policyTable =DBMANAGER::$tablesPrefix."Policy";
	$roleTable =DBMANAGER::$tablesPrefix."Role";
        //VERSION with ID_Resource different from name...
	//$query = 'DELETE FROM Policy where ID_Role = (select ID from Role where name =\''. $roleName .'\') and ID_Resource = (select ID from Resource where name =\''. $resName  .'\')';
        $query = "DELETE FROM $policyTable  where ID_Role = (select ID from $roleTable  where name =\'". $roleName .'\') and ID_Resource = \''. $resName  .'\' ';
        $logManager->query($query, "delete() Policy");
        $results = $db->exec($query);
        return $results; //is an int
}
//OK
public function createResource( $name, $description ){

	$resourceTable =DBMANAGER::$tablesPrefix."Resource";
        $table = $resourceTable;
        $actual_date = date("Y-m-d H:i:s");
        $guidGenerator = new GuidGenerator;
        $ID = $guidGenerator->generate();
        $qm = new QueryManager;
        $fields = array("ID", "name", "description");
        $values = array($ID,  $name, $description);
    try{
                $qm->insertTable($table,$fields,$values);
    } catch(Exception $e){
        $results = $e->getMessage();
    }
    return $ID;
}


}
?>
