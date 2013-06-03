#! /usr/bin/perl

use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);
use lib qw(.);

use Account;
use Policy;
use Resource;
use Role;
use Usergroup;
use User;


&create_Account();
&create_Policy();
&create_Resource();
&create_Role();
&create_Usergroup();
&create_User();

my $created = localtime();
my $updated = localtime();

###
###
$admin_user_id = &getguidstring();
my $password ="admin"; 
my $password_hash =sha1_hex($password);
my $name ="admin";
my $surname ="user"; 
my $nickname ="admin"; 
my $openid =""; 

&save_User("$admin_user_id", "$openid","$created", "$password_hash", "$nickname", "$name", "$updated", "$surname" );

$anon_user_id = &getguidstring();
my $password =""; 
my $password_hash =sha1_hex($password);
my $name ="anonymous";
my $surname ="user"; 
my $nickname ="anon"; 
my $openid =""; 

&save_User("$anon_user_id", "$openid","$created", "$password_hash", "$nickname", "$name", "$updated", "$surname" );

###
###

my $users_usergroup_id=&getguidstring();;
my $description="Generic users group";
my $name="users";
&save_Usergroup( "$users_usergroup_id", "$created", "$name", "$updated", "$description" );


my $wheel_usergroup_id=&getguidstring();;
my $description="System administration user group";
my $name="wheel";
&save_Usergroup( "$wheel_usergroup_id", "$created", "$name", "$updated", "$description" );


##
##

my $sys_role_id=&getguidstring();;
my $description="System administration tasks";
my $name="sys";
&save_Role( "$sys_role_id", "$created", "$name", "$updated", "$description" );



my $generic_role_id=&getguidstring();;
my $description="Generic tasks";
my $name="generic";
&save_Role( "$generic_role_id", "$created", "$name", "$updated", "$description" );

my $common_role_id=&getguidstring();;
my $description="Least available access";
my $name="common";
&save_Role( "$common_role_id", "$created", "$name", "$updated", "$description" );


##
##

my $draft_resource_id=&getguidstring();;
my $description="A draft model";
my $name="draft";
my $externaltable="";
my $type="internal.draft";
my $internal="1";
my $data="__Payload_Data__";

&save_Resource( "$draft_resource_id", "$name", "$data", "$description", "$created", "$externaltable", "$type", "$updated", "$internal" );


##
##

my $account_id = &getguidstring();
my $ID_User = $admin_user_id;
my $ID_Role = $sys_role_id;
my $ID_Usergroup = $users_usergroup_id;
my $active = "1"; ### Create ACTIVE accounts

&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );

my $account_id = &getguidstring();
my $ID_User = $anon_user_id;
my $ID_Role = $generic_role_id;
my $ID_Usergroup = $wheel_usergroup_id;
my $active = "0";

&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );


my $admin_policy_id = &getguidstring();
my $ID_Resource = $draft_resource_id;
my $ID_Role = $sys_role_id;
my $description = "System Role";
my $perms = "111"; #RWX
&save_Policy ( "$admin_policy_id", "$created", "$ID_Resource", "$updated", "$ID_Role", "$description", "$perms" );

my $user_policy_id = &getguidstring();
my $ID_Resource = $draft_resource_id;
my $ID_Role = $generic_role_id;
my $description = "Generic Role";
my $perms = "100"; #R

&save_Policy ( "$user_policy_id", "$created", "$ID_Resource", "$updated", "$ID_Role", "$description", "$perms" );



###################################
#
sub getguidstring(){
        my $guid;
        chomp($guid=`uuidgen`);
        return $guid;
}

