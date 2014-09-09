<?php
session_start(); 
unset($_SESSION['USER']);
unset($_SESSION['registry']);
unset($_SESSION['logoff']);
session_destroy();
?>

