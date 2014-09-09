<?php

/****
	Provides the actual implementation of methods called via RpcGateway
*/
	include("../settings.inc");
	require_once(BACKEND_DIR."/kernel/UserDAO.class.inc");


	require_once(BACKEND_DIR."/kernel/LogManager.class.inc");
	require_once(BACKEND_DIR."/kernel/Registry.class.inc");
	require_once(BACKEND_DIR."/kernel/AuthManager.class.inc");//TODO: to delete
	

	function test_connection()
	{
		return 1;
	}


	function user_getnick($userid)
	{
		session_start();
        	$userdo = new UserDAO;
        	$nick = $userdo->getNickname($userid);
		return $nick;
	}


	function auth_login($username, $password)
	{
		session_start();
        	$mgr = new AuthManager;
		$userid = $mgr->login($username, $password);
		return $userid;
	}

	function registry_getregistry($userid)
	{
		session_start();
		$reg = new Registry;
		$registry = $reg->getRegistry($userid);
		return $registry;
	}



////////////////////////
	
	/**
	 * Returns a test value containing an indexed array.
	 **/
	
	function test_xmlrpc_array()
	{
		return array('a', 'b', array('cc' => 'ccc'), array('aaa, bbb, ccc'));
	}

	function test_xmlrpc_assoc()
	{
		return array('a' => 'aa', 'b' => 'bb', 'c' => array('aaa', 'bbb', 'ccc'), 'd' => array('dd' => 'ddd'));
	}

?>
