<?

$system = php_uname("s");

define ("USE_AJAX","true");

define ("BACKEND_DIR",  "/home/paolo/apps/hbf");
define ("WWWDIR",  "/var/www/hbf");
define ("WEBSITE",  "default");
define ("WEBROOT",  "http://127.0.0.1/hbf");
define ("CSSROOT" , WEBROOT."/css");
define ("LOGROOT" , BACKEND_DIR."/logs");
define ("DBROOT" ,  BACKEND_DIR."/db");
define ("DB_FILE" , DBROOT."/webauth.db");


define ("EXTJSROOT", WEBROOT."/lib/extjs");
define ("EXTJS_CSSROOT", EXTJSROOT."/resources/css");
define ("EXTJS_JSROOT", EXTJSROOT."/adapter/ext");
define ("EXTJS_CUSTOMROOT",EXTJSROOT."/custom");

?>
