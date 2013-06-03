<?php

$type = '';
$action ='';
$id ='';

if (isset($_REQUEST['id']) ){
	$id = $_REQUEST['id'];
}

if (isset($_REQUEST['type'])){
	$action ="LIST";
	$type = $_REQUEST['type'];
}

if (isset($_REQUEST['action']) && isset($_REQUEST['id'] )){

	if ($_REQUEST['action'] == 'delete'){ 
		$action ="DELETE";
	}
	if ($_REQUEST['action'] == 'insert'){ 
		$action ="INSERT";
	}
} else {
	$action ="RETRIEVE";
}
echo "Action: [". $action ."] ";
echo "Type: [". $type ."] ";
echo "Id: [". $id ."] ";

?>
