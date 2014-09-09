#! /usr/bin/perl

use DBI;
use strict;

use lib qw(../lib);
use dbiclient;

use lib qw(../conf);
use configuration;


 
my $create_Policy_query= " create table Policy(  
	ID char(36)
	, created date
	, ID_Resource varchar(36)
	, updated date
	, ID_Role varchar(36)
	, description varchar(256)
	, perms varchar(12)  );";
sub create_Policy(){
       	&launch_query($create_Policy_query);
}
 

sub save_Policy($$$$$$){


my $ID = $_[0];
my $created = $_[1];
my $ID_Resource = $_[2];
my $updated = $_[3];
my $ID_Role = $_[4];
my $description = $_[5];
my $perms = $_[6];
my $sql = "insert into Policy values ( '$ID', '$created', '$ID_Resource', '$updated', '$ID_Role', '$description', '$perms' )";

&launch_query($sql);

}


 
sub update_Policy_equals($$$){

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