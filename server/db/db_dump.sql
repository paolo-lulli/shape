BEGIN TRANSACTION;
CREATE TABLE Account(  
	ID varchar(256)
	, created date
	, ID_Group varchar(256)
	, ID_User varchar(256)
	, active int
	, updated date
	, ID_Role varchar(256)  );
CREATE TABLE Policy(  
	ID varchar(256)
	, created date
	, ID_Resource varchar(256)
	, updated date
	, ID_Role varchar(256)
	, description varchar(256)
	, perms varchar(12)  );
CREATE TABLE Resource(  
	ID varchar(256)
	, data blob
	, description varchar(256)
	, created date
	, ID_Resource varchar(256)
	, externaltable varchar(256)
	, type varchar(256)
	, updated date
	, internal int  );
CREATE TABLE Role(  
	ID varchar(256)
	, created date
	, updated date
	, description varchar(256)  );
CREATE TABLE Usergroup(  
	ID varchar(256)
	, created date
	, updated date
	, description varchar(256)  );
CREATE TABLE User(  
	ID varchar(256)
	, created date
	, password varchar(256)
	, name varchar(256)
	, updated date
	, surname varchar(256)  );
COMMIT;
