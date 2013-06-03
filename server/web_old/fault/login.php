<?
session_start();

require_once("web.inc");
file_get_contents(WWWDIR."/".WEBSITE."/blocks/header.inc");
/*
require_once(ROOT."/kernel/LogManager.class.inc");
require_once(ROOT."/kernel/UserDAO.class.inc");
require_once(ROOT."/kernel/Registry.class.inc");
*/
echo "<div name=\"infoblock\" />";
include(WWWDIR."/".WEBSITE."/blocks/infoblock.inc");

echo "<script type=\"text/javascript\" src=\"Login.js\"></script>";
echo "<div id=\"loginMsg\"></div>";


/////////
include(WWWDIR."/".WEBSITE."/blocks/footer.inc");
?>
