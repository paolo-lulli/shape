<?php

require_once 'LogManager.class.inc';

class GenericDao
{
//var tableName;


/*
public function getObjectById($id){
}
*/


public function getConnection(){
 	$db = DBManager::getInstance();
	return $db;
}



}
?>
