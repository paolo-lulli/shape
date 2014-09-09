<?php

//require_once("../../../conf/backend.inc");
include(BACKEND_DIR."/kernel/ResourceModel.class.inc");

class FbcmdInterfaceResource extends ResourceModel
{

public function execute(){ 
	echo 'execute';
}
public function read(){
	echo 'read';
}
public function write(){
	echo 'write';
}

public function install(){
	echo 'install';
}
public function uninstall(){
	echo 'uninstall';
}
public function info(){
	echo 'info';
}

}

?>
