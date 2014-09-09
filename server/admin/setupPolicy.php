<?php
require_once("../conf/backend.inc");
require_once(BACKEND_DIR."/kernel/ResourceManager.class.inc");
require_once(BACKEND_DIR."/kernel/GuidGenerator.class.inc");
require_once(BACKEND_DIR."/kernel/QueryManager.class.inc");

require_once(BACKEND_DIR."/kernel/PolicyDao.class.inc");

$policyDao = new PolicyDao;
//$policyDao-> assignResourceToRole("Test", "role-commandline");
$policyDao-> assignResourceToRole("Test", "role-web-admin");




?>
