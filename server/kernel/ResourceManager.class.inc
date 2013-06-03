<?php

    //require_once 'Log.php';
//    require_once ("../conf/backend.inc");
    //require_once("GuidGenerator.class.inc");
    //require_once 'AuthManager.class.inc';
    require_once ("LogManager.class.inc");
    require_once ("DBManager.class.inc");

class ResourceManager
{


    public function installResource($res_name){ 

    $user_id     = $_REQUEST['USER'];
    $role_id     = $_REQUEST['ROLE'];
    $resource_id = $_REQUEST['RESOURCE'];

    $updated = date("Y-m-d H:i:s");
    $created = date("Y-m-d H:i:s");

    //$resource_manager = ner ResourceManager;

    $resource = $this->loadResourceFromFile($res_name);

    $data    = $resource['data'];
    $setup   = $resource['setup'];
    $display = $resource['display'];
    $resource_class = $resource['class'];

    require_once($setup);
    require_once($data);
    require_once($display);
    require_once($resource_class);

    $db = DBManager::getInstance();
    $query = sprintf("insert into Resource (ID, name, data, 
    	description, created, externaltable, 
    	type, updated, internal) values('%s','%s','%s','%s','%s','%s','%s','%s','%s' )", 
        $res_name,
        $res[$res_name]['name'], 
        "", //data ...
        $res[$res_name]['description'],
        $created,
        "",
        $res[$res_name]['type'],
        $updated,
        1);
    echo $query;

    $db->query($query);

    $class = $res_name . 'Resource';
    $object = new $class();
    $object->install();

    }

    public function loadResourceFromFile($res_name){

    //$auth_mgr = new AuthManager;

    $setup          =  BACKEND_DIR . "/resources/" . $res_name . "/setup.inc"; //TODO: add controls on $res_name
    $data           =  BACKEND_DIR . "/resources/" . $res_name . "/data.inc"; 
    $display        =  BACKEND_DIR . "/resources/" . $res_name . "/display.inc"; 
    $resource_class =  BACKEND_DIR . "/resources/" . $res_name . "/module/". $res_name . "Resource.class.inc"; 

    $resource['setup'] = $setup;
    $resource['data'] = $data;
    $resource['display'] = $display;
    $resource['class'] = $resource_class;

    return $resource;
    }

    public function execute($res_name){
    	$resource_class =  BACKEND_DIR . "/resources/" . $res_name . "/module/". $res_name . "Resource.class.inc"; 
    	require_once($resource_class);
    	$class = $res_name . 'Resource';
    	$object = new $class();
    	$object->execute();
    }

     public function getResource($res_name){
        $resource_class =  BACKEND_DIR . "/resources/" . $res_name . "/module/". $res_name . "Resource.class.inc";
        require_once($resource_class);
        $class = $res_name . 'Resource';
        $object = new $class();
        return $object;
    }

    /*
    TODO

    public function loadResourceOnDb($res_name){}
    public function zipResource($res_name){}
    public function saveResourceToFile($res_name){}
    public function loadResourceFromDb($res_name){}
    */
}
?>
