<?php
if ( empty($_SESSION['USER'])){
echo "<div id=\"login\">\n";
echo "<form method=\"post\" action=\"". htmlspecialchars($_SERVER['PHP_SELF'])."\" >\n";
echo "<input type=\"text\" name=\"username\">username</input>\n";
echo "<input type=\"text\" name=\"password\">password</input>\n";
echo "<input type=\"hidden\" name=\"login\" value=\"true\"/>\n";
echo "<input type=\"submit\" id=\"submit\" value=\"login\"\"/>\n";
echo "</form>\n";
echo "</div>\n";
} 
else {

echo "[<a href=\"";
echo htmlspecialchars($_SERVER['PHP_SELF'])."?logoff=1\" >\n";
echo "logoff</a>]";
/*
$userdo = new UserDAO;
$nick = $userdo->getNickname($_SESSION['USER']);
echo 'You are: [<b>';
echo $nick;
echo ']</b>';
*/
}

?>
