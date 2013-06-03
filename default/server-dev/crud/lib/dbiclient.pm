#! /usr/bin/perl

use DBI;
use strict;

#
# provide easy db-calls via Perl DBI to Databases
# 
# Paolo Lulli 2008

our $dbname;
our $dbusername;
our $dbpassword;
our $dbtype;

#our $dbtype="SQLite";
#our $dbtype="mysql";

############################################################################

sub 
launch_query($){

my $query = $_[0];

    my $dbargs = {AutoCommit => 0,
                  PrintError => 1};

    my $dbh = DBI->connect("dbi:$dbtype:dbname=$dbname","$dbusername","$dbpassword",$dbargs) or die("cannot connect");

    $dbh->do($query);

    if ($dbh->err()) { die "$DBI::errstr\n"; }

    $dbh->commit();
    $dbh->disconnect();

}
##############################################################################

sub 
launch_select($){

my $query = $_[0];
my %ret_hash;
my $ret_array;

    my $dbargs = {AutoCommit => 1,
                  PrintError => 1};

    my $dbh = DBI->connect("dbi:$dbtype:dbname=$dbname","$dbusername","$dbpassword",$dbargs) or die("cannot connect");

    $ret_array = $dbh->selectall_arrayref("$query");

    my $dbargs = {AutoCommit => 0,
                  PrintError => 1};

    if ($dbh->err()) { die "$DBI::errstr\n"; }

    #$dbh->finish();
    $dbh->disconnect();

    return @$ret_array; 
}
##############################################################################
1;
