<?
session_start();


//include("../settings.inc");

require_once(ROOT_BACKEND."/kernel/LogManager.class.inc");
require_once(ROOT_BACKEND."/kernel/UserDAO.class.inc");
require_once(ROOT_BACKEND."/kernel/Registry.class.inc");

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
