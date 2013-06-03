<?php


abstract class ConfigurationInterface
{
//User Data Acquisition
public abstract function registerUser( $name, $surname, $nickname, $password, $openid );

//Account Management
public abstract function createAccount($userid, $group_name, $role_name);
public abstract function activateAccount($account_id);
public abstract function deactivateAccount($account_id);

//Roles Creation
public abstract function createRole($name, $description);
public abstract function deleteRole($roleName);

//Resources Installation
public abstract function installResource($resName);
public abstract function deleteResource($resName);
public abstract function addResourceToRole($resName, $roleName);
public abstract function removeResourceFromRole($resName, $roleName);

}

?>
