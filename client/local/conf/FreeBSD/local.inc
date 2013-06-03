<?php

/*
	define("RPCPROXY_GATEWAY",  "/rpc.php");
	define("RPCPROXY_HOST",  "lulli.net");
	define("RPCPROXY_PORT",  "80");
*/

	define("ROOT", "/home/blacksheep/apps/dbt");
 	define("CLIENT_DIR", ROOT."/local");
	define("BACKEND_DIR", ROOT."/server");
	define("SHARED_DIR", BACKEND_DIR."/shared");
 	define("LOGROOT", CLIENT_DIR."/logs");
	define("CONNECTION_STRING", "sqlite:prova.db");
	//define(CONNECTION_STRING, "mysql:host=localhost;dbname=periodic_table", 'username', 'password');

?>
