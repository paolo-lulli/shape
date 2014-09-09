<?php

require("env.inc");
require_once("SecurityManager.class.inc");

$sm = new SecurityManager;
//$sm->createKeys($passphrase);
$sm->createUserKeys("user",$passphrase);
$sm->createServerKeys($passphrase);

?>
