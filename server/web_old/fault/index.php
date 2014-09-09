<?
	include_once("web.inc");
	include(WWWDIR."/default/registry.inc");

	$template = $_REQUEST['t'];
	$is_debug = $_REQUEST['d'];


if (($template == "")||($template == "default")){
	include(WWWDIR."/".WEBSITE."/blocks/header.inc");
//echo "<div name=\"infoblock\" />";


if ( $is_debug == "1") {
	var_dump($_SESSION['registry']);
}

	include(WWWDIR."/".WEBSITE."/blocks/infoblock.inc");
	include(WWWDIR."/".WEBSITE."/blocks/footer.inc");

}
if ($template == "login"){
	include(WWWDIR."/".WEBSITE."/login.php");
}
if ($template == "logoff"){
	include(WWWDIR."/".WEBSITE."/logoff.php");
}
else if( $template == "portal" ){
	include(WWWDIR."/".WEBSITE."/load_portal.inc");
}

?>

