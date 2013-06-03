<?php

class DBManager{

private static $instance = NULL;

private function __clone(){
}


private function __construct() {
  /*** maybe set the db name here later ***/
}

public static function getInstance() {

  //$conn_string = "sqlite:" . DB_FILE;
	//TODO
  //$conn_string = CONNECTION_STRING;

if (!self::$instance)
    {
	try {
    		//self::$instance = new PDO($conn_string);

    		//self::$instance = new PDO("mysql:host=127.0.0.1;dbname=hbf_01", 'hbf_01', 'hbf_01');
    		self::$instance = new PDO("mysql:host=127.0.0.1;dbname=dbthunde_gest", 'dbthunde_gest', 'dbthunde_gest');
    		self::$instance-> setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch(PDOException $e) {
    		echo $e->getMessage();
	}
    }
return self::$instance;
}

}

?>

