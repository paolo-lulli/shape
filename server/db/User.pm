#! /usr/bin/perl

use DBI;
use strict;

use lib qw(../lib);
use dbiclient;

use lib qw(../conf);
use configuration;


 
my $create_User_query= " create table User(  
	ID char(36)
	, openid varchar(256)      
	, created date
	, password varchar(256)
	, nickname varchar(256)
	, name varchar(256)
	, updated date
	, surname varchar(256)  );";
sub create_User(){
       	&launch_query($create_User_query);
}
 

sub save_User($$$$$$$){


my $ID = $_[0];
my $openid = $_[1];
my $created = $_[2];
my $password = $_[3];
my $nickname = $_[4];
my $name = $_[5];
my $updated = $_[6];
my $surname = $_[7];
my $sql = "insert into User values ( '$ID', '$openid', '$created', '$password', '$nickname', '$name', '$updated', '$surname' )";

&launch_query($sql);

}


 
sub update_User_equals($$$){

my $tableName = $_[0];
my $rKeyValuePairs = $_[1];
my $rWhere = $_[2];

my %wherea = %{$rWhere};
my %keyValuePairs = %{$rKeyValuePairs};

my $updatefields_set = " SET ";
my $updatefields_where = " WHERE ";
my $field;

my $keyssize = keys( %keyValuePairs );
my $wheresize = keys( %wherea );

my $fieldcount = 0;
foreach $field (keys(%keyValuePairs)){
	$fieldcount++; 
	print "field ---- $field
";
	print "SIZE:  $keyssize
";
	$updatefields_set.= "$field = '$keyValuePairs{\"$field\"}'";
	print "SET -------------->  $updatefields_set\n";
	if (  $fieldcount <=  $keyssize -1 ){
		$updatefields_set.= " , ";
	}
}

$fieldcount = 0;
foreach $field (keys(%wherea)){
	$fieldcount++; 
	$updatefields_where .= "$field =  '$wherea{\"$field\"}'" ;
	print "WHERE ----------->  $updatefields_where
";
}

my $sql = "update $tableName $updatefields_set  $updatefields_where ";

&launch_query($sql);
}





1; 
