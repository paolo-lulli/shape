<?php

require_once("SecurityManager.class.inc");
require("env.inc");


$data="aiaiaiaiaiaiaiai ii iii ii iiaiaiaiaiaia iaiaiaaiiaiaiauno strano racconto di cose";

$sm = new SecurityManager;
$ciphered = $sm->cryptRequest($data, $passphrase);
echo "$ciphered";

//$cleartext=$sm->decryptRequest($ciphered, $passphrase);
$cleartext=$sm->decryptRequest($ciphered);
echo 'cleartext='.$cleartext;

?>
