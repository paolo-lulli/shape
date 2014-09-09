<?php
require('../../../rpcclient/conf/local.inc');
require_once(ROOT."/client/plugin/Zero/classes/ZeroDao.class.inc");

$dao = new ZeroDao;
$table="zero";
$types= array("int","int","int");
$fields= array("AAA","BBB","CCC");

var_dump($dao);
$dao->create($table, $fields, $types);

?>
