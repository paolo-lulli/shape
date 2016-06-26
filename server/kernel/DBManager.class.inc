<?php

class DBManager{

private static $instance = NULL;
public static $tablesPrefix = 'shp_';

private function __clone(){
}


private function __construct() {
  /*** maybe set the db name here later ***/
}

public static function getInstance() {

if (!self::$instance)
    {
	try {
    		self::$instance = new PDO("pgsql:host=127.0.0.1;dbname=wired_usm", 'postgres', 'postgres');
    		self::$instance-> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch(PDOException $e) {
    		echo $e->getMessage();
	}
    }
return self::$instance;
}

}

?>

