#!  /usr/bin/perl

use strict;

use File::Copy;

use XML::Simple;
use strict;
use lib "lib";
use crud;

use lib "conf";
use crud_configuration;

our $table_name;
our %table_attributes;  
our $crud_build_directory;

my $crud_lib_directory;
my $crud_conf_directory;
my $crud_auth_directory;

my $xml = new XML::Simple;
my $data;
my @tabelle;
my $field;
my $tabella;
my $rtabella;
my %table;

$data = $xml->XMLin($ARGV[0]);

my %database = %{$data};

my $idx = 0;
foreach $tabella (keys(%database)){
	@tabelle[$idx] = $tabella;

	print "Table: [$tabella]\n";
	print "------------------------------------------\n";
	$rtabella = $database{"$tabella"};
	%table = %{$rtabella};
	foreach $field (keys(%table)){
		print "Field [$field]\t is type: [$table{$field}] \n";
	}
	$idx++;
	$table_name = $tabella;
	%table_attributes =  %table;
	$crud_lib_directory = $crud_build_directory . "\/lib";
	$crud_conf_directory = $crud_build_directory . "\/conf";
	$crud_auth_directory = $crud_build_directory . "\/auth";
	mkdir($crud_lib_directory);
	mkdir($crud_conf_directory);
	copy("lib/dbiclient.pm", $crud_lib_directory);
	copy("auth/db_auth.pm", $crud_conf_directory);
	copy("auth/web_auth.pm", $crud_conf_directory);
	copy("conf/configuration.pm", $crud_conf_directory);
	chdir($crud_build_directory);
	&create_module($table_name, \%table_attributes);
	#%table_attributes = ();
}
