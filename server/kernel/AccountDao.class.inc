<?php
//require_once('../conf/backend.inc');
require_once(BACKEND_DIR.'/conf/backend.inc');

require_once(BACKEND_DIR.'/kernel'.'/ConfManager.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/UsergroupDao.class.inc');
require_once(BACKEND_DIR.'/kernel'.'/RoleDao.class.inc');


class AccountDao
{

public function insertAccount($userid, $roleid, $groupid){
	$accountTable =DBMANAGER::$tablesPrefix."Account";
        $table = $accountTable;
        $active_default = "1"; //May be set to 0
        $actual_date = date("Y-m-d H:i:s");
        $guidGenerator = new GuidGenerator;
        $ID = $guidGenerator->generate();
        $qm = new QueryManager;
        $fields = array("ID", "created", "ID_User", "active", "updated", "ID_Role","ID_Usergroup");
        //$fields = array("id", "created", "id_user", "active", "updated", "id_role","id_usergroup");
        $values = array($ID, $actual_date, $userid, $active_default, $actual_date, $roleid, $groupid); //BUG: unnecessary ID_User (?)
        try{
                $qm->insertTable($table,$fields,$values);
        } catch(Exception $e){
                $results = $e->getMessage();
        }
//var_dump($results);
return $ID;
}

}
?>
