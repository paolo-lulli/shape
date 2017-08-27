Shape Framework
==================

Version 12 December 2010  - by Paolo Lulli
<http://lulli.net/>

Introduction
------------

This is only a short introduction to the Shape Framework. 

Shape Framework features:

- Service Oriented Architecture
- 3-Tier architecture
- MVC engine
- Flexible RBAC Authentication 
- Portable Database Query Engine

Packages and Bundle(s)
---------------------

You may need installing one of the following bundles:

- A complete remote SERVER solution 			[server_xmlrpc]
- A CLIENT for a local server 				[client_local]
- A RPC CLIENT for a remote server 			[client_xmlrpc]
- A full local install of both SERVER and CLIENT 	[full]

All these bundle result from some combination of the following packages:

- shape-client-local    
- shape-client-rpc      
- shape-server-backend  
- shape-server-frontend 
- shape-server-gateway  
- shape-server-web

which provide the full set of features.


Role-Based (RBAC) Authentication
---------------------------------
![RBAC model](https://raw.github.com/madunixman/shape/master/shared/doc/rbac.png)

Install
-------

### Remote server 

On the local machine

    cd $APPLICATION_HOME/install

    ./install-remote.sh     

then, ssh on the remote machine you're going to install, and cd to the directory

	cd $REMOTE_BACKEND_INSTALL_DIR/server/admin

launch the following script:

	./init.sh

it initializes the database and the log directory.


### Client  

    cd $APPLICATION_HOME/install

    ./install-local-client.sh 

### Local Server 

    cd $APPLICATION_HOME/install

    install-local-server.sh 


Programming Interface
---------------------

### Configuration Manager

All top-level configurations are available from the ConfManager class; it exposes the following methods:

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

For example, to call the

	registerUser(...)

method we can code the following:

	require_once('../conf/backend.inc');
	require_once(BACKEND_DIR.'/kernel'.'/ConfManager.class.inc');
	$cm = new ConfManager;
	$userid = $cm->registerUser( "name", "mysurname", "mynick", "mypassword", "myemail@email.com");

N.B.: 

	backend.inc

is the backend configuration file; above all, it sets the value for the 

	BACKEND_DIR

constant
