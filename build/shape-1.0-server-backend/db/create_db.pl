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
$root_user_id = &getguidstring();
my $password ="root"; 
my $password_hash =sha1_hex($password);
my $name ="root";
my $surname ="user"; 
my $nickname ="root"; 
my $openid =""; 

&save_User("$root_user_id", "$openid","$created", "$password_hash", "$nickname", "$name", "$updated", "$surname" );

$generic_user_id = &getguidstring();
my $password =""; 
my $password_hash =sha1_hex($password);
my $name ="test";
my $surname ="user"; 
my $nickname ="test"; 
my $openid =""; 

&save_User("$generic_user_id", "$openid","$created", "$password_hash", "$nickname", "$name", "$updated", "$surname" );

###
###

my $users_usergroup_id=&getguidstring();;
my $description="Generic users group";
my $name="group-users";
&save_Usergroup( "$users_usergroup_id", "$created", "$name", "$updated", "$description" );


my $wheel_usergroup_id=&getguidstring();;
my $description="System administration user group";
my $name="group-wheel";
&save_Usergroup( "$wheel_usergroup_id", "$created", "$name", "$updated", "$description" );


##
##

my $webadmin_role_id=&getguidstring();;
my $description="System administration tasks";
my $name="role-web-admin";
&save_Role( "$webadmin_role_id", "$created", "$name", "$updated", "$description" );

my $commandline_role_id=&getguidstring();;
my $description="System administration tasks";
my $name="role-commandline";
&save_Role( "$commandline_role_id", "$created", "$name", "$updated", "$description" );


my $generic_role_id=&getguidstring();;
my $description="Generic tasks";
my $name="role-generic";
&save_Role( "$generic_role_id", "$created", "$name", "$updated", "$description" );

#my $common_role_id=&getguidstring();;
#my $description="Least available access";
#my $name="common";
#&save_Role( "$common_role_id", "$created", "$name", "$updated", "$description" );



my $account_id = &getguidstring();
my $ID_User = $root_user_id;
my $ID_Role = $webadmin_role_id;
my $ID_Usergroup = $users_usergroup_id;
my $active = "1"; ### Create ACTIVE accounts
&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );
# root to role-web-admin

my $account_id = &getguidstring();
my $ID_User = $root_user_id;
my $ID_Role = $commandline_role_id;
my $ID_Usergroup = $users_usergroup_id;
my $active = "1"; ### Create ACTIVE accounts
&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );
# root to role-commandline

my $account_id = &getguidstring();
my $ID_User = $root_user_id;
my $ID_Role = $generic_role_id;
my $ID_Usergroup = $users_usergroup_id;
my $active = "1"; ### Create ACTIVE accounts
&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );
# root to role-generic

my $account_id = &getguidstring();
my $ID_User = $generic_user_id;
my $ID_Role = $generic_role_id;
#my $ID_Usergroup = $wheel_usergroup_id;
my $ID_Usergroup = $wheel_usergroup_id;
my $active = "0";
# test user to role-generic

&save_Account ( "$account_id", "$created", "$ID_User", "$active", "$updated", "$ID_Role", "$ID_Usergroup" );


my $admin_policy_id = &getguidstring();
my $ID_Resource = $draft_resource_id;
my $ID_Role = $webadmin_role_id;
my $description = "System Role";
my $perms = "111"; #RWX
&save_Policy ( "$admin_policy_id", "$created", "$ID_Resource", "$updated", "$ID_Role", "$description", "$perms" );

my $user_policy_id = &getguidstring();
my $ID_Resource = $draft_resource_id;
my $ID_Role = $generic_role_id;
my $description = "Generic Role";
my $perms = "100"; #R

&save_Policy ( "$user_policy_id", "$created", "$ID_Resource", "$updated", "$ID_Role", "$description", "$perms" );


############
my $draft_resource_id=&getguidstring();;
my $description="A draft model";
my $name="draft";
my $externaltable="";
my $type="internal.draft";
my $internal="1";
my $data="__Payload_Data__";

&save_Resource( "$draft_resource_id", "$name", "$data", "$description", "$created", "$externaltable", "$type", "$updated", "$internal" );



###################################
#
sub getguidstring(){
        my $guid;
	my $os;
        chomp($os=`uname -s`);
	if ($os eq "FreeBSD"){
        	chomp($guid=`/usr/compat/linux/usr/bin/uuidgen`);
		# Why the hell on FreeBSD standard uuidgen gives ALWAYS the same value ?
	}else {
        	chomp($guid=`uuidgen`);
	}
        return $guid;
}

