<?php

//require_once(BACKEND_DIR."/kernel/ResourceManager.class.inc");
require_once("ResourceManager.class.inc");

abstract class ResourceModel
{

public abstract function read();
public abstract function write();
public abstract function execute();

public abstract function install();
public abstract function uninstall();
public abstract function info();

}

?>


