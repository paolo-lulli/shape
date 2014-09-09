<?php

require_once("../../../local/conf/local.inc");
require_once(BACKEND_DIR."/kernel/QueryManager.class.inc");

class ZeroDao
{
public static $table = "zero";


public	static $fields  = array("ID"
		, "eee"
		, "u"
	);

public	static $types  = array("varchar(256)"
		, "date"
		, "varchar"
	);

private	$values= array("ID __VALUE__"
		, "eee __VALUE__"
		, "u __VALUE__"
	);
/*
$selected = array("a", "b");
contains the desired fields in the results for a select 

$aliases = array("ALIAS_a", "ALIAS_b");
is an array containing the n-th alias for the n-th selected field
*/

public function create(){
	$qm = new QueryManager;
	$qm->createTable($table,$fields,$types);
}

//$qm->create($table,$fields,$types);
//$qm->select($table,$fields,$values,NULL, NULL);
//$qm->select($table,$fields,$values,$selected, $aliases);
//$qm->update($table,$fields,$values,$where_fields, $where_values);
//$qm->delete($table,$fields,$values,$where_fields, $where_values);
//$qm->insert($table,$fields,$values);

}

?>
