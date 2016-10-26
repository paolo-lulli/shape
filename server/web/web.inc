<?

$system = php_uname("s");

define ("USE_AJAX",		"true");
define ("WWWDIR",  		dirname(__FILE__));
define ("WEBROOT",  		"http://dbthunder.com/erw/");
define ("CSSROOT" , 		WEBROOT."/css");       // web path

if( !defined('BACKEND_DIR')) {
	define ("BACKEND_DIR",  	"/home2/dbthunde/.apps/erw");
}
if( !defined('LOGROOT')) {
	define ("LOGROOT" , 		BACKEND_DIR."/logs"); // local path
}

//FOR DEBUG:
//error_reporting(E_ALL);
//ini_set('display_errors', 'On');


?>

