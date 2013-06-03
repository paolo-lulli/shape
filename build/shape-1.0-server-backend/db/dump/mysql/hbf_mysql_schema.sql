CREATE TABLE Account(  
	ID char(36)
	, created date
	, ID_User varchar(36)
	, active int
	, updated date
	, ID_Role varchar(36)
	, ID_Usergroup varchar(36)  
 	, PRIMARY KEY  (`ID`)
);
CREATE TABLE Policy(  
	ID char(36)
	, created date
	, ID_Resource varchar(36)
	, updated date
	, ID_Role varchar(36)
	, description varchar(256)
	, perms varchar(12)  
 	, PRIMARY KEY  (`ID`)
);
CREATE TABLE Resource(  
	ID char(36)
	, name varchar(256)
	, data blob
	, description varchar(256)
	, created date
	, externaltable varchar(256)
	, type varchar(256)
	, updated date
	, internal int  
 	, PRIMARY KEY  (`ID`)
	, UNIQUE KEY `name` (`name`)
);
CREATE TABLE Role(  
	ID char(36)
	, created date
	, name varchar(256)
	, updated date
	, description varchar(256)  
 	, PRIMARY KEY  (`ID`)
	, UNIQUE KEY `name` (`name`)
);
CREATE TABLE User(  
	ID char(36)
	, openid varchar(256)      
	, created date
	, password varchar(256)
	, nickname varchar(256)
	, name varchar(256)
	, updated date
	, surname varchar(256)  
 	, PRIMARY KEY  (`ID`)
	, UNIQUE KEY `nickname` (`nickname`)
	, UNIQUE KEY `openid` (`openid`)
);
CREATE TABLE Usergroup(  
	ID char(36)
	, created date
	, name varchar(256)
	, updated date
	, description varchar(256)  
 	, PRIMARY KEY  (`ID`)
	, UNIQUE KEY `name` (`name`)
);
