<?
session_start();


//include("../settings.inc");

require_once(BACKEND_DIR."/kernel/LogManager.class.inc");
require_once(BACKEND_DIR."/kernel/UserDAO.class.inc");
require_once(BACKEND_DIR."/kernel/Registry.class.inc");

$lm = new LogManager;

//$lm->debug("Session id: [".session_id()."]","index.php");

if (! empty($_SESSION['USER'])){
	$userdo = new UserDAO;
	$nick = $userdo->getNickname($_SESSION['USER']);

	$registry = new Registry;
	$registry = $registry->init($_SESSION['USER']);
	//$role = $registry->getRoles();
	//if( sizeof(
	//$registry = $registry-> setRoleByName($registry, $role);
	
	$_SESSION['registry'] =  $registry;
}

?>
