<?
session_start();

$nick="anonymous";
include("../settings.inc");
//include(ROOT."/ajax/blocks/header.inc");
require_once(ROOT."/kernel/LogManager.class.inc");
require_once(ROOT."/kernel/UserDAO.class.inc");
require_once(ROOT."/kernel/Registry.class.inc");

$lm = new LogManager;

//$lm->debug("Session id: [".session_id()."]","index.php");

if (! empty($_SESSION['USER'])){
	$userdo = new UserDAO;
	$nick = $userdo->getNickname($_SESSION['USER']);

	$registry = new Registry;
	$registry = $registry->init($_SESSION['USER']);
	$_SESSION['registry'] =  $registry;
}

echo $nick;
/* TODO:
   implement here an async call to infoblock.php infos...

*/
//echo "<div name=\"infoblock\" />";
//include(ROOT."/ajax/blocks/infoblock.inc");



/////////
//include(ROOT."/ajax/blocks/footer.inc");
?>
