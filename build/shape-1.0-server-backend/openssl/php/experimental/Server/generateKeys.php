<?php

require("env.inc");
require_once("SecurityManager.class.inc");

$sm = new SecurityManager;
$sm->createKeys($passphrase);

?>
