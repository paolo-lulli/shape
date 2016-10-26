<?php

//Needed for JSONP
//------------------------------------------------
header('Cache-Control: no-cache, must-revalidate');
header('Expires: Mon, 26 Jul 1997 05:00:00 GMT');
header('Content-type: application/json');
//------------------------------------------------

session_start();
require_once("../web.inc");
require_once(BACKEND_DIR."/kernel/LogManager.class.inc");
$lm = new LogManager;

include_once(BACKEND_DIR."/kernel/AuthManager.class.inc");
$auth_manager = new AuthManager();

$password = "";
if (! empty ($_REQUEST['password'])){
	$password = $_REQUEST['password'];
}
$hash_pass = sha1($password);

/*
if (!isset($_SESSION['password'])) {
	$_SESSION['password'] = $hash_pass;
}
*/
$user_nick = "";
if (! empty ($_REQUEST['username'])){
	$user_nick = $_REQUEST['username'];
}

//echo "YOU GAVE pass: [$hash_pass] for user: [$user_nick]";

unset($_SESSION['USER']);

$logon = $auth_manager->login($user_nick, $hash_pass);
//echo "pass: [$hash_pass] logged with user: [$logon]";

if (!isset($_SESSION['USER'])) {
	$_SESSION['USER'] = $logon;
} else {
	unset($_SESSION['USER']);
	$_SESSION['USER'] = "0";
}
$lm->debug("Login USER:[". $_SESSION['USER']. "]", "login.php");
$lm->info("Login USER:[". $_SESSION['USER']. "]", "login.php");

print "xhr_login(".json_encode($_SESSION['USER']).");";
//print json_encode($_SESSION['USER']);
?>
