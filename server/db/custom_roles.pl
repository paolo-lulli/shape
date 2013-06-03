#! /usr/bin/perl

use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);

use lib qw(lib);
use dbiclient;

use lib qw(conf);
use configuration;

use lib qw(.);

use Account;
use Policy;
use Resource;
use Role;
use Usergroup;
use User;


my $created = localtime();
my $updated = localtime();


my $role_id=&getguidstring();
my $description="Developer Role which can do anything";
my $name="commandline";
&save_Role( "$role_id", "$created", "$name", "$updated", "$description" );


my $ID=&getguidstring();
my $ID_Resource = "Test";
my $ID_Role = $role_id;
my $description="policy that assigns [Test] to role [commandline]";
&save_Policy ( "$ID", "$created", "$ID_Resource", "$updated", "$ID_Role", "$description", "$perms" );



##
#
sub getguidstring(){
        my $guid;
        chomp($guid=`uuidgen`);
        return $guid;
}
