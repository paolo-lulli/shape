<?

//require_once("settings.inc");
require_once(BACKEND_DIR."/kernel/UserDAO.class.inc");

$userdo = new UserDAO;

$nick = $userdo->getNickname($_SESSION['USER']);
//echo "--->$nick\n";
$roles = $userdo->getRoles($_SESSION['USER']);

print "<br/>Available Roles: ";
while (list ($key, $val) = each ($roles)) {
#echo "$key -> $val";
echo " $val <br/>";
}

$groups = $userdo->getGroups($_SESSION['USER']);
print "<br/>Groups: ";
while (list ($key, $val) = each ($groups)) {
#echo "$key -> $val";
echo " $val <br/>";
}
//echo "\n";
//echo count($roles);


?>
