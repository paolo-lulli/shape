<?

session_start();
$username = $_POST['username'];
$password = $_POST['password'];
$real_name = $_POST['real_name'];
$real_surname = $_POST['real_surname'];
$submitted    = $_POST['submitted'];

if ( $submitted == 'true'){
include('db_auth.inc');

$link = mysql_connect ($db_host, $db_user, $db_pass)
or die ("Non riesco a connettermi");
mysql_select_db($db_instance);

mysql_query ("insert into  SCR_USER values ( '$username', md5('$password'), '$real_name', '$real_surname', now(), now() )")
or die ("Query non valida");
//echo "Query avvenuta correttamente";

mysql_close($link); 
} // Non fa nulla

?>
