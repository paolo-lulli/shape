#!/usr/bin/perl

use XML::Simple;
use Data::Dumper;

# create object
$xml = new XML::Simple;

# read XML file
$data = $xml->XMLin($ARGV[0]);

print Dumper($data);

my $xmldata = XMLout($data , NoAttr => 1);
print  $xmldata;
