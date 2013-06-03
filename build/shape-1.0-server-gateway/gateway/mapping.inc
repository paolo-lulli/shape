<?php
/**
	Provides the mapping between Rpc remote methods and their implementation 
	contained in 'implementation.php'
*/

//		'user.getnick' => 'user_getnick',
	$api_mapping = array(
		'test.connection' => 'test_connection',
		'registry.get' => 'registry_getregistry',
		'user.getnick' => 'user_getnick',
		'auth.login' => 'auth_login',
	);
	/*
		'dateTest' => 'test_xmlrpc_date_test',
		'assoc' => 'test_xmlrpc_assoc',
		'array' => 'test_xmlrpc_array',
	*/
?>
