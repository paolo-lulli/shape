#! /usr/bin/perl

use DBI;
use strict;

use lib qw(../lib);
use dbiclient;

use lib qw(../conf);
use configuration;


 
my $create_Resource_query= " create table Resource(  
	ID char(36)
	, name varchar(256)
	, data blob
	, description varchar(256)
	, created date
	, externaltable varchar(256)
	, type varchar(256)
	, updated date
	, internal int  );";
sub create_Resource(){
       	&launch_query($create_Resource_query);
}
 

sub save_Resource($$$$$$$$){


my $ID = $_[0];
my $name = $_[1];
my $data = $_[2];
my $description = $_[3];
my $created = $_[4];
my $externaltable = $_[5];
my $type = $_[6];
my $updated = $_[7];
my $internal = $_[8];
my $sql = "insert into Resource values ( '$ID', '$name', '$data', '$description', '$created', '$externaltable', '$type', '$updated', '$internal' )";

&launch_query($sql);

}


 
sub update_Resource_equals($$$){

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