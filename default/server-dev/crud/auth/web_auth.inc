<?

$username = $_POST['username'];
$password = $_POST['password'];
$login    = $_SESSION['login'];

if ( $login == 'false' ){
session_start();
$_SESSION['login'] = 'true';
}

include('db_auth.inc');
/*
$db_host = '';
$db_user = '';
$db_pass = '';
$db_instance = '';
*/

$link = mysql_connect ($db_host, $db_user, $db_pass)
or die ("Non riesco a connettermi");
mysql_select_db($db_instance);


$result = mysql_query ("select * from  SCR_USER where id_USER = '$username' and password = md5('$password') ")
or die ("Query non valida");
echo "Query avvenuta correttamente";
$user = mysql_fetch_assoc($result); 

if (mysql_num_rows($result) == 0) {
    echo "No rows found, nothing to print so am exiting";
}else{
$_SESSION['username']= $user["id_USER"];
$_SESSION['group']='user'; 
}

mysql_close($link); 
echo "you are"; 
echo $user["id_USER"];
?>
