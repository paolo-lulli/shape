<?php
require_once("QueryBuilder.class.inc");

$qb = new QueryBuilder;

$aliases = array("ALIAS_a", "ALIAS_b");
$selected = array("a", "b");

$fields = array("a", "b", "c");
$values = array("val_a", "val_b", "val_c");
$types = array("type_a", "type_b", "type_c");
$table= 'try_tab';

//echo $qm->selectSql($table,$fields,$values,NULL, NULL);
//echo $qm->selectSql($table,$fields,$values,$selected, $aliases);
//echo $qm->updateSql($table,$fields,$values,$selected, $aliases);
echo $qb->deleteSql($table,$fields,$values,$selected, $aliases);
//echo $qm->insertSql($table,$fields,$values);

?>
