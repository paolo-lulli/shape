<?php
$page['title'] = "titolo";
$page['header'] = file_get_contents(WWWDIR."/new/header.inc");
$page['menu']  = "menu";
$page['navigation'] = "navigation";
$page['main'] = "main";
$page['footer'] = "footer";

include(WWWDIR."/new/portal_a.php");

?>
