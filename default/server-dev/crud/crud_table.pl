#!  /usr/bin/perl

use strict;
use lib qw(lib);
use crud;

my $tablename;

if ($#ARGV == 0){
	$tablename=$ARGV[0];
	print "$#ARGV,  $tablename";
} else {
	$tablename = &prompt("Table Name: ");
}
&generate_table_xml($tablename);

