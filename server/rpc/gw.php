<?php
	error_reporting(E_ALL);
	/*
	!! Workaround not to re-define BACKEND_DIR !!
	define("BACKEND_DIR","/home/blacksheep/apps/dbt");
	*/
  	$BACKEND="/home/blacksheep/apps/hbf";
	require($BACKEND.'/conf/backend.inc');


	//include("../settings.inc");
	require(BACKEND_DIR.'/gateway/XRPC_Server.php');

	/*****************************/
	include(BACKEND_DIR."/gateway/implementation.inc");
	include(BACKEND_DIR."/gateway/mapping.inc");
	/*****************************/

	$server = new XRPC_Server($api_mapping);
	
	$server->detectDateTime = true;
	$server->handleRequest();
?>
