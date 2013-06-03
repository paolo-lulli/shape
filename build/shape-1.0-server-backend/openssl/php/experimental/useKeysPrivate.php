<?php

require_once("SecurityManager.class.inc");
require("env.inc");


$data="uno strano racconto di cose";

$sm = new SecurityManager;
$ciphered = $sm->crypt($data, $passphrase);
echo "$ciphered";

$cleartext=$sm->decryptWithPrivateKey($ciphered, "fake");
echo 'cleartext='.$cleartext;

?>
