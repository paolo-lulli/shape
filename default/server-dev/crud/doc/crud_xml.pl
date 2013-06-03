#!  /usr/bin/perl

use strict;
use lib qw(lib);
use crud;

our $table_name = "oz";
our %table_attributes = 
	(
	"nome" => "text" , 
	"cognome" => "text" 
	);



&dump_xml($table_name, \%table_attributes);

