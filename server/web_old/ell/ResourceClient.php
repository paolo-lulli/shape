<?php
require_once("settings.inc");
require_once(ROOT."/kernel/ResourceManager.class.inc");
$resManager = new ResourceManager;

$resource = $resManager->loadResourceFromFile('zero');

$data  = $resource['data'];
$setup = $resource['setup'];
$display = $resource['display'];

require_once($setup);
require_once($data);
require_once($display);

?>
