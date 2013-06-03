<?php
require('../../rpcclient/conf/rpc.inc');
require_once(CLIENT_DIR."/classes/CrudRpcClient.class.inc");

$client = new CrudRpcClient;
$table="prova";
$types= array("int","int","int");
$fields= array("AAA","BBB","CCC");

$client->create($table, implode(",",$fields), implode(",",$types));

?>
