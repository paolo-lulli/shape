<?php

//require_once("./conf/settings.inc");
require_once(BACKEND_DIR."/QueryManager.class.inc");

class UserDao extends QueryManager
{

static $table = "User";


static $fields  = array("ID"
		, "openid"
		, "created"
		, "password"
		, "nickname"
		, "name"
		, "updated"
		, "surname"
	);

private static $types  = array("varchar(256)"
		, "varchar"
		, "date"
		, "varchar(256)"
		, "varchar(256)"
		, "varchar(256)"
		, "date"
		, "varchar(256)"
	);

var $values= array("ID __VALUE__"
		, "openid __VALUE__"
		, "created __VALUE__"
		, "password __VALUE__"
		, "nickname __VALUE__"
		, "name __VALUE__"
		, "updated __VALUE__"
		, "surname __VALUE__"
	);

public function create(){
	try{
		$qm = new QueryManager;
		$qm->createTable($this::$table, $this::$fields, $this::$types);
	} catch (Exception $e){
		echo $e->getMessage();
	}
}

public function select(){
	try{
		$qm = new QueryManager;
		$qm->selectTable($this::$table,$this::$fields,$this::$values,$this::$selected, $this::$aliases);
	} catch (Exception $e){
		echo $e->getMessage();
	}
}

public function update(){
	try{
		$qm = new QueryManager;
		$qm->updateTable($this::$table,$this::$fields,$this::$values,$this::$where_fields, $this::$where_values);
	} catch (Exception $e){
		echo $e->getMessage();
	}
}

public function delete(){
	try{
		$qm = new QueryManager;
		$qm->deleteTable($this::$table,$this::$fields,$this::$values,$this::$where_fields, $this::$where_values);
	} catch (Exception $e){
		echo $e->getMessage();
	}
}

public function insert($table,$fields,$values){
	try{
		$qm = new QueryManager;
		$qm-> insertTable($table,$fields,$values);
	} catch (Exception $e){
		echo $e->getMessage();
	}
}


//$qm->create($table,$fields,$types);
//$qm->select($table,$fields,$values,NULL, NULL);
//$qm->select($table,$fields,$values,$selected, $aliases);
//$qm->update($table,$fields,$values,$where_fields, $where_values);
//$qm->delete($table,$fields,$values,$where_fields, $where_values);
//$qm->insert($table,$fields,$values);

}
?>
