<?

$system = php_uname("s");

define ("USE_AJAX",		"true");
define ("WWWDIR",  		"/home2/dbthunde/www/open/gestionale");
define ("WEBROOT",  		"http://open.lulli.net/gestionale");
define ("CSSROOT" , 		WEBROOT."/css");       // web path

if( !defined('BACKEND_DIR')) {
	define ("BACKEND_DIR",  	"/home2/dbthunde/apps/hbf");
}
if( !defined('LOGROOT')) {
	define ("LOGROOT" , 		BACKEND_DIR."/logs"); // local path
}

//************************** FOR DEBUG:
//error_reporting(E_ALL);
//ini_set('display_errors', 'On');


?>
