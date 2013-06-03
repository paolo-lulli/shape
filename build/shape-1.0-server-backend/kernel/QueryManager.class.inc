<?php

require_once("QueryBuilder.class.inc");
require_once("LogManager.class.inc");
require_once("DBManager.class.inc");

class QueryManager extends QueryBuilder
{

public static function createTable($table, $fields, $types){
	//$queryBuilder = new QueryBuilder;
	$db = DBManager::getInstance();
	$logManager = new LogManager;
	$query = parent::createSql($table, $fields, $types);
	$logManager->query($query, "create()". $table);
	$results = $db->exec($query);
	return $results; //is an int
	
}
public static function updateTable($table, $fields, $values, $where_fields, $where_values){
	//$queryBuilder = new QueryBuilder;
	$db = DBManager::getInstance();
	$logManager = new LogManager;
	$query = parent::updateSql($table, $fields, $values, $where_fields, $where_values);
	$logManager->query($query, "update()". $table);
	$results = $db->exec($query);
	return $results; //is an int
}
public static function insertTable($table, $fields, $values){
	//$queryBuilder = new QueryBuilder;
	$db = DBManager::getInstance();
	$logManager = new LogManager;
	$query = parent::insertSql($table, $fields, $values);
	$logManager->query($query, "insert()". $table);
	$results = $db->exec($query);
	return $results; //is an int
}
//public static function delete($table, $fields, $values , $where_fields, $where_values){
public static function deleteTable($table, $where_fields, $where_values){
	//$queryBuilder = new QueryBuilder;
	$db = DBManager::getInstance();
	$logManager = new LogManager;
	//$query = parent::deleteSql($table, $fields, $values , $where_fields, $where_values);
	$query = parent::deleteSql($table, $where_fields, $where_values);
	$logManager->query($query, "delete()". $table);
	$results = $db->exec($query);
	return $results; //is an int
}
public static function selectTable( $table, $fields, $values, $selected, $aliases ){
        $db = DBManager::getInstance();
        $logManager = new LogManager;
        $results = 0;
        $query = parent::selectSql($table, $fields, $values, $selected, $aliases );
        $logManager->query($query, "select()". $table);
        try{
                $results=array();
                $sth = $db->prepare($query);
                $sth->execute();
                $results = $sth->fetchAll();
                //print_r($result);
        } catch(Exception $e){
                $results = $e->getMessage();
        }
        return $results;
}


/*
public static function selectAllSql($table, $fields, $values){
$db = DBManager::getInstance();
}
*/
}
?>
