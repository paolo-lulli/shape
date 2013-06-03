<?php
require_once("QueryManager.class.inc");

$qm = new QueryManager;

$aliases = array("ALIAS_a", "ALIAS_b");
$selected = array("a", "b");

$fields = array("a", "b", "c");
$values = array("val_a", "val_b", "val_c");
$types = array("varchar[32]", "int", "varchar");
$table= 'try_tab';

//echo $qm->selectSql($table,$fields,$values,NULL, NULL);
//echo $qm->selectSql($table,$fields,$values,$selected, $aliases);
//echo $qm->updateSql($table,$fields,$values,$selected, $aliases);
//echo $qm->deleteSql($table,$fields,$values,$selected, $aliases);
echo $qm->createTable($table,$fields,$types);
echo $qm->insertTable($table,$fields,$values);
//echo $qm->deleteSql($table,$fields,$values,$selected, $aliases);

?>
