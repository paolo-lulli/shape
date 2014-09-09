<?php
$page['title'] = "titolo";
$page['header'] = file_get_contents(WWWDIR."/default/load_portal/header.inc");
$page['menu']  = "menu";
$page['navigation'] = "navigation";
$page['main'] = "main";
$page['footer'] = "footer";

include(WWWDIR."/templates/portal.php");

?>
