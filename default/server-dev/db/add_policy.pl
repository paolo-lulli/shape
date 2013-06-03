#! /usr/bin/perl

#use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);
use lib qw(.);

use Account;
use Policy;
use Resource;
use Role;
use Usergroup;
use User;



my $created = localtime();
my $updated = localtime();
my $draft_resource_id=&getguidstring();;
my $description="A block model";
my $name="block";
my $externaltable="";
my $type="internal.block";
my $internal="1";
my $data="";

#&save_Resource( "$draft_resource_id", "$name", "$data", "$description", "$created", "$externaltable", "$type", "$updated", "$internal" );

&save_Policy ( '$ID', '$created', '$ID_Resource', '$updated', '$ID_Role', '$description', '$perms' )";

###################################
#
sub getguidstring(){
        my $guid;
        chomp($guid=`uuidgen`);
        return $guid;
}


