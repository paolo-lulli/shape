<?php

require_once('./lib/RpcClient.class.inc');

$client = new RpcClient;
$userid = $client->performLogin("admin","admin");
$registry = $client->getRegistry($userid);

var_dump($registry);

?>
