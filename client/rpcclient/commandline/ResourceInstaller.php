<?php
require_once("../www/settings.inc");
require_once(ROOT."/kernel/ResourceManager.class.inc");
$resManager = new ResourceManager;

//$resManager->aaa();
$resManager->installResource("Test");
//$resManager->loadResourceFromFile("zero");

?>
