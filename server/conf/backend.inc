<?php

	define("RPCPROXY_GATEWAY",  "/rpc.php");
	define("RPCPROXY_HOST",  "localhost");
	define("RPCPROXY_PORT",  "80");
	//define("CONNECTION_STRING", "sqlite:".BACKEND_DIR."/data.db");
  	define("CONNECTION_STRING", "sqlite:". BACKEND_DIR ."/db/webauth.db");
define ("DBROOT" ,  BACKEND_DIR."/db");
define ("DB_FILE" , DBROOT."/webauth.db");

if( !defined('BACKEND_DIR')) {
        define("BACKEND_DIR", "/home2/dbthunde/apps/hbf");
}
if( !defined('LOGROOT')) {
        define("LOGROOT", BACKEND_DIR."/logs");
}


	//define("CONNECTION_STRING", "sqlite:prova.db");
	//define(CONNECTION_STRING, "mysql:host=localhost;dbname=periodic_table", 'username', 'password');

?>
