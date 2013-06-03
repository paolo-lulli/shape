#!/usr/bin/perl

use XML::Simple;
#use Data::Dumper;

my $xml = new XML::Simple;
my $data = $xml->XMLin($ARGV[0]);
my @tabelle;
my $field;
my $tabella;
my $rtabella;
my %database = %{$data};
my %table;

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
}
