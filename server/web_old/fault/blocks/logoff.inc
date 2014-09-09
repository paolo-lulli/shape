<?php
//session_start(); If included, it is called above
unset($_SESSION['USER']);
unset($_SESSION['registry']);
unset($_SESSION['logoff']);

session_destroy();
?>
