<?php
require_once("settings.inc");
require_once(ROOT."/kernel/ResourceProxy.class.inc");
$resProxy = new ResourceProxy;

$res_name = "zero";
$resource = $resProxy->getResource($res_name, $user_id, $role_id, $resource_id);

//$resource = $resProxy->loadResourceFromFile('zero');

$data  = $resource['data'];
$setup = $resource['setup'];
$display = $resource['display'];

require_once($setup);
require_once($data);
require_once($display);

?>
