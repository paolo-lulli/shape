<?php
session_start();

	include(WWWDIR."/auth/registry.inc");
 	require_once(BACKEND_DIR."/kernel/AuthManager.class.inc");
        require_once(BACKEND_DIR."/kernel/Registry.class.inc");
        $authManager = new AuthManager;
        $id_user = $_SESSION['USER'];
        $registry = $_SESSION['registry'];
        $id_role = $registry[$id_user]['id_role'];
        echo "nick: $nick<br/>";
        echo "id_user: $id_user<br/>";
        echo "id_role: $id_role<br/>";
?>
