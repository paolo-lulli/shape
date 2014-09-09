<?php
require("./conf/settings.inc");
require(BACKEND_DIR."/GuidGenerator.class.inc");

require("./php/UsergroupDao.class.inc");
require("./php/UserDao.class.inc");
require("./php/RoleDao.class.inc");
require("./php/AccountDao.class.inc");
require("./php/PolicyDao.class.inc");
require("./php/ResourceDao.class.inc");

$gg = new GuidGenerator;

$user_dao = new UserDao;
$usergroup_dao = new UsergroupDao;
$role_dao = new RoleDao;
$account_dao = new AccountDao;
$policy_dao = new PolicyDao;
$resource_dao = new ResourceDao;

$user_dao	->create();
$usergroup_dao	->create();
$role_dao	->create();
$account_dao	->create();
$policy_dao	->create();
$resource_dao	->create();

$guid = $gg->generate();
$values= array("$guid"
		, ""
		, date("Y-m-d H:i:s") 
		, sha1("admin")
		, "admin"
		, "admin"
		, date("Y-m-d H:i:s") 
		, "user"
	);

$user_dao->insert($user_dao::$table,$fields,$values);
$guid = $gg->generate();
$values= array("$guid"
		, "" // OpenID
		, date("Y-m-d H:i:s") 
		, sha1("")
		, "anonymous"
		, "anonymous"
		, date("Y-m-d H:i:s") 
		, "user"
	);

$user_dao->insert($user_dao::$table,
	$fields,
	$values);

?>
