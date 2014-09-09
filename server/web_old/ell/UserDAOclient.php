<?

require_once("settings.inc");
require_once(ROOT."/kernel/UserDAO.class.inc");

$userdo = new UserDAO;

$nick = $userdo->getNickname('7c1bcaeb-71bf-4cac-9b6b-ed5dca7b097c');
echo "--->$nick\n";
$roles = $userdo->getRoles('7c1bcaeb-71bf-4cac-9b6b-ed5dca7b097c');

//print "roles:" . $roles;
while (list ($key, $val) = each ($roles)) {
echo "$key -> $val";
}

echo "\n";
echo count($roles);

?>
