<?php
require_once("../conf/backend.inc");
require_once(BACKEND_DIR."/kernel/ResourceManager.class.inc");
$resManager = new ResourceManager;

//$resManager->execute("Test");
$res = $resManager->getResource("Test");
$res->execute();

?>

