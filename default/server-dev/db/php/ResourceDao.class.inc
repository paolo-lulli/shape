<?php

//require_once("./conf/settings.inc");
require_once(BACKEND_DIR."/QueryManager.class.inc");

class ResourceDao extends QueryManager
{

private static $table = "Resource";


static $fields  = array("ID"
		, "name"
		, "data"
		, "description"
		, "created"
		, "externaltable"
		, "type"
		, "updated"
		, "internal"
	);

private static $types  = array("varchar(256)"
		, "varchar(256)"
		, "blob"
		, "varchar(256)"
		, "date"
		, "varchar(256)"
		, "varchar(256)"
		, "date"
		, "int"
	);

static $values= array("ID __VALUE__"
		, "name __VALUE__"
		, "data __VALUE__"
		, "description __VALUE__"
		, "created __VALUE__"
		, "externaltable __VALUE__"
		, "type __VALUE__"
		, "updated __VALUE__"
		, "internal __VALUE__"
	);
/*
$selected = array("a", "b");
contains the desired fields in the results for a select 

$aliases = array("ALIAS_a", "ALIAS_b");
is an array containing the n-th alias for the n-th selected field
*/

public function create(){
	try{
		$qm = new QueryManager;
		$qm->createTable($this::$table,$this::$fields,$this::$types);
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

public function insert(){
	try{
		$qm = new QueryManager;
		$qm-> insertTable($this::$table,$this::$fields,$this::$values);
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
