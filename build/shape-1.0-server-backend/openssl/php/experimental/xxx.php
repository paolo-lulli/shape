<?php

require_once("SecurityManager.class.inc");
require("env.inc");


$data="uno strano racconto di cose";

$sm = new SecurityManager;
$modelReflector = new ReflectionClass('SecurityManager');
#
$method = $modelReflector->getMethod('crypt');
#
$parameters = $method->getParameters();
var_dump($parameters);


//echo $parameters[0]['name'];
$x = new ReflectionParameter;
$x = $parameters[0];

echo $x['name'];

?>
