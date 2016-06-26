<?php

require_once 'LogManager.class.inc';
require_once 'DBManager.class.inc';
require_once 'GenericDao.class.inc';


$db = DBManager::getInstance();
$userTable =DBMANAGER::$tablesPrefix;
//."User";

echo $userTable;
