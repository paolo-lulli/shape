<?php

$url = "http://www.acme.com/products/3322";
$response = file_get_contents($url);
echo $response;

?>
