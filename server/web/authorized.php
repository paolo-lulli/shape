<?
$resource_id = "draft";

        include_once("web.inc");
        include("registry.inc");

        require_once(BACKEND_DIR."/kernel/AuthManager.class.inc");
        require_once(BACKEND_DIR."/kernel/Registry.class.inc");
        $authManager = new AuthManager;

        //$nick = $userdo->getNickname($_SESSION['USER']);
        $user_id = $_SESSION['USER'];
        $registry = $_SESSION['registry'];
        //$registry = $registry->getRegistry($user_id);
        $role_id = $registry[$user_id]['role'];
        echo "nick: $nick<br/>";
        echo "user_id: $user_id<br/>";
        echo "role_id: $role_id<br/>";
?>

<?php   

if ($authManager->authResource($user_id, $role_id, $resource_id)){
//if(true){

?>
<html>
<head>

</head>
<body>
aaaa
</body>
<?php
} else {
        echo "<b>Resource NOT authorized</b>";
}
?>

