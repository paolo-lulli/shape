<?php

    include("AuthManager.class.inc");

/*

    USER = 02998DF2-76A7-4BC3-A45C-3E76E05E9A12
USERGROUP = A3E0839B-F9F2-4C79-9015-579C14234781
     ROLE = E7D1D672-C984-4A85-829A-69D0836CDA7F
 RESOURCE = 7FA77244-99D9-4394-8151-AF401DC7E580


*/
$_REQUEST['USER']="02998DF2-76A7-4BC3-A45C-3E76E05E9A12";
$_REQUEST['ROLE']="E7D1D672-C984-4A85-829A-69D0836CDA7F";
$_REQUEST['RESOURCE']="7FA77244-99D9-4394-8151-AF401DC7E580";
$user_id =$_REQUEST['USER'];
$role_id =$_REQUEST['ROLE'];
$resource_id =$_REQUEST['RESOURCE'];

$user_nick="admin";
$user_password="d033e22ae348aeb5660fc2140aec35850c4da997";


    $manager = new AuthManager();
    echo "USERID: $user_id\n";
    echo "ROLEID: $role_id\n";
    echo "RESOURCEID: $resource_id\n";
    echo $manager->authResource($user_id, $role_id, $resource_id);
    echo "\n--->"; //. "$yourclass->getRead()";
    $logon = $manager->login($user_nick, $user_password);
    echo "logged with user: [$logon]";
?>
