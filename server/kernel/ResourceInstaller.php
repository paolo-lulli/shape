<?php
require_once("../conf/backend.inc");
require_once(BACKEND_DIR."/kernel/ResourceManager.class.inc");
$resManager = new ResourceManager;

$resource_name ="Test";

//$resManager->aaa();
$resManager->installResource($resource_name);
//$resManager->execute("Test");
//$resManager->loadResourceFromFile("zero");

?>
