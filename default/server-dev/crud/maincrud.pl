#!  /usr/bin/perl

use strict;
use lib "lib";
use crud;

my $option;
my $choice;
my $action_performed;
my $table_name;
my $xml_name;

if ( ($#ARGV != 0) && ($#ARGV != 1) && ($#ARGV != 2)   ){
	&usage();
	exit(0);
}
if ($#ARGV == -1 ){
	$option = "NEWTABLE";
} else {
	$choice =  $ARGV[0];

	if (( $choice eq "-a" ) || ($choice eq "add")){
		$option = "NEWTABLE";
		if ($#ARGV == 1) {
			$table_name =  $ARGV[1];
			print "RUN NEWTABLE $table_name";
			&generate_table_xml($table_name);
			$action_performed++;
		}
	} else {
                $option = "CREATE";
                $action_performed++;
		$xml_name =  $ARGV[1];
		print "RUN CREATE $xml_name";
        }




	##############################
	if ($action_performed == 0 ) {
 		&usage();
         	exit(0);
	}

}

__DATA__

Usage:
	crud (with no args)
	crud add (-a) [table-name]
