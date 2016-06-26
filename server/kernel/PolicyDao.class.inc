<?php

//require_once("../conf/backend.inc");
require_once(BACKEND_DIR."/kernel/LogManager.class.inc");
require_once(BACKEND_DIR."/kernel/DBManager.class.inc");
require_once(BACKEND_DIR."/kernel/GenericDao.class.inc");
require_once(BACKEND_DIR."/kernel/RoleDao.class.inc");

require_once(BACKEND_DIR."/kernel/ResourceManager.class.inc");
require_once(BACKEND_DIR."/kernel/GuidGenerator.class.inc");
require_once(BACKEND_DIR."/kernel/QueryManager.class.inc");

class PolicyDao extends GenericDao
{
//var $tableName ="shp_Policy";


public function getObjectById($id){
}

public function insertPolicy($id_resource, $id_role, $perms, $description){

}

public function assignResourceToIdRole($resource_name, $id_role, $description){
	$userTable =DBMANAGER::$tablesPrefix."User";
	$roleTable =DBMANAGER::$tablesPrefix."Role";
	$accountTable =DBMANAGER::$tablesPrefix."Account";
	$usergroupTable =DBMANAGER::$tablesPrefix."Usergroup";
	$policyTable =DBMANAGER::$tablesPrefix."Policy";
        $table = $policyTable;
        $qm = new QueryManager;
        $resManager = new ResourceManager;
        $guidGenerator = new GuidGenerator;
        $guid = $guidGenerator->generate();
        $actual_date = date("Y-m-d H:i:s");
//$resource_name ="Test";
//$resManager->installResource($resource_name);

        $fields = array("ID","created","ID_Resource","updated", "ID_Role","description","perms");
	if ( $description == ""){
        	$description = "Assigns Resource [".$resource_name."] to ID_Role [".$id_role."]";
	}
        $values = array($guid, $actual_date,$resource_name,$actual_date, $id_role,$description,"111");
        $qm->insertTable($table,$fields,$values);
}


public function assignResourceToRole($resource_name, $role_name){
	$roleDao = new RoleDao;
	$id_role = $roleDao->getRoleId($role_name);
        $comment ="Assigns resource [".$resource_name."] to Role [".$role_name."]";
 	$this->assignResourceToIdRole($resource_name, $id_role, $comment);
}




}
?>
