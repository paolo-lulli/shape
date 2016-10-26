<?
	session_start();
        include_once("../web.inc");
	require_once(BACKEND_DIR."/kernel/AuthManager.class.inc");
	//$resource_id = "CustomerMgr";
	$resource_id = "InterpreterMgr";
	$id_user = $_SESSION['USER'];
	$id_role = $_SESSION['registry'][$id_user]['id_role'];
?>


<?php 

print("<br/>\nresource_id=".$resource_id);
print("<br/>\nid_user=".$id_user);
print("<br/>\nid_role=".$id_role);

$authManager = new AuthManager;
if ($authManager->authResource($id_user, $id_role, $resource_id)){ 
?>
<html>
<head>
</head>
<body>
Hello, <?=$id_user;?>
</body>
<?php } else { ?>
        <b>Resource NOT authorized</b>
<?php } ?>

