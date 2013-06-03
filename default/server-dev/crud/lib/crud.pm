#!  /usr/bin/perl

use strict;

our %table_attributes;
our $table_name;




my $header=<<EOT;
#! /usr/bin/perl

use DBI;
use strict;

use lib qw(../lib);
use dbiclient;

use lib qw(../conf);
use configuration;


EOT


sub
create_module($table_name, %table_attributes){
my $table = $_[0];
my $rAttributes = $_[1];

my %attributes = %{$rAttributes};

##############mkdir($table);
##############chdir($table);
mkdir("php");
my $modulefilename = $table.".pm";
my $createfilename = "client.pl";
my $insertfilename = "insert.pl";


my $insert_form_filename = "form_".$table.".inc";
my $insert_php_filename = "insert_".$table.".php";

unlink ($modulefilename);
unlink ($createfilename);
unlink ($insertfilename);

open (F, ">>", $modulefilename);

print F "$header";

print "Table name [$table] with fields:\n";
my $key;

#################my $types_block ="\n\tID varchar(256)";
my $types_block ="\n\tID char(36)";
foreach $key (keys(%attributes)){
	if ( $key ne "ID" ){
        	$types_block .= "\n\t, $key $attributes{$key}"
	}
	}


my $create_block=<<EOT;

my \$create\_$table\_query= " create table $table(  $types_block  );";
sub create_$table(){
       	&launch_query(\$create\_$table\_query);
}
EOT
print F " $create_block";


my $form_input="";
my $insert_args="";
my $insert_values="\'\$ID\'";
my $insert_vars="\nmy \$ID = \$\_[0];";
my $counter = 0;
foreach $key (keys(%attributes)){
	$counter++;
	$insert_args.="\$";
	$insert_values.=", \'\$$key\'";
	$insert_vars.="\nmy \$$key = \$\_[$counter];";
	$form_input .= "<input type=\"text\" name=\"$key\">$key</input>\n";
}
my $insert_block=<<EOT;


sub save\_$table($insert_args){

$insert_vars
my \$sql = "insert into $table values ( $insert_values )";

&launch_query(\$sql);

}


EOT
print F " $insert_block";
my $update_block=<<EOT;

sub update\_$table\_equals(\$\$\$){

my \$tableName = \$_[0];
my \$rKeyValuePairs = \$_[1];
my \$rWhere = \$_[2];

my \%wherea = %{\$rWhere};
my \%keyValuePairs = \%{\$rKeyValuePairs};

my \$updatefields_set = " SET ";
my \$updatefields_where = " WHERE ";
my \$field;

my \$keyssize = keys( \%keyValuePairs );
my \$wheresize = keys( \%wherea );

my \$fieldcount = 0;
foreach \$field (keys(\%keyValuePairs)){
	\$fieldcount++; 
	print "field ---- \$field\n";
	print "SIZE:  \$keyssize\n";
	\$updatefields_set.= "\$field = \'\$keyValuePairs{\\\"\$field\\\"}\'";
	print "SET -------------->  \$updatefields_set\\n";
	if (  \$fieldcount <=  \$keyssize -1 ){
		\$updatefields_set.= " , ";
	}
}

\$fieldcount = 0;
foreach \$field (keys(\%wherea)){
	\$fieldcount++; 
	\$updatefields_where .= "\$field =  \'\$wherea{\\\"\$field\\\"}\'" ;
	print "WHERE ----------->  \$updatefields_where\n";
}

my \$sql = "update \$tableName \$updatefields_set  \$updatefields_where ";

&launch_query(\$sql);
}



EOT
print F " $update_block";

print F "\n\n1; ";
close(F);

open (F, ">>", $createfilename);
my $createfile=<<EOT;
#!  /usr/bin/perl

#use lib qw($table);
use $table;

create\_$table();
EOT
print F "$createfile";
close(F);

open (F, ">>", $insertfilename);
my $insertfile=<<EOT;
#!  /usr/bin/perl

#use lib qw($table);
use $table;

save\_$table($insert_values);
save\_$table("ieria", "iiiiiun titolo di prova");

##################printall\_draft();
EOT
print F "$insertfile";
close(F);

#chmod ('755', $createfilename);
#chmod ('755', $insertfilename);

chdir("php");


open (F, ">>", $insert_form_filename);

my $insert_form=<<EOT;
<form method="post" action="<?php echo htmlspecialchars(\$_SERVER['PHP_SELF']);?>">
$form_input
<input type=\"submit\" value=\"insert\"></input>
</form>
EOT
print F "$insert_form";
close(F);

open (F, ">>", $insert_php_filename);

my $insert_php=<<EOT;
<?php
//include('../../auth/web_auth.inc');
include('../../auth/add\_$table.inc');
include('header.inc');
//

include('$insert_form_filename');



include('footer.inc');
?>


EOT
print F "$insert_php";
close(F);

####################
foreach $key (keys(%attributes)){
	print "Field [$key] of type: [$attributes{$key}]\n";
}


}

sub 
dump_xml($table_name, %table_attributes){
my $table = $_[0];
my $rAttributes = $_[1];

my %attributes = %{$rAttributes};

my %tab;
$tab{"$table"} =  \%attributes;


use XML::Simple;
my $xml = XMLout(\%tab, NoAttr => 1);
#my $xml = XMLout(\%table );
print $xml;

}

sub 
dump_xml_string($table_name, %table_attributes){
my $table = $_[0];
my $rAttributes = $_[1];

my %attributes = %{$rAttributes};

my %tab;
$tab{"$table"} =  \%attributes;


use XML::Simple;
my $xml = XMLout(\%tab, NoAttr => 1);
#my $xml = XMLout(\%table );
return $xml;

}


sub
prompt($){
my $pr_string = $_[0];
my $app;
print "$pr_string";
$app = <STDIN>;
chomp($app);
return $app;
}

sub
hash_key_chooser($$){
my $key;
my $r_h = $_[0];
my %h = %{$r_h};
my $s = $_[1];
my @appo;
my $idx = 1;
my $choice = 0;

        foreach (sort (keys %h)){
                #if($h{$_}=~/$s/){ # Se l'alias rispetta la regexp
                if($_=~/$s/){ # Se l'alias rispetta la regexp
                        $appo[$idx] = $_;
                        $idx++;
                }
        }
        #$idx = 0;
        for($idx = 1; $idx < ($#appo +1 ) ; $idx++ ){
                print "[$idx]\t : $appo[$idx] \n";
        }
        print "\n[0]\t to exit\n\n";
        chomp($choice = <STDIN>);
        $key = $appo[$choice];
        if ( $choice == 0 ) {
                print "No Action to take\n";
                exit(0);
        }
return $key
}


sub
choose_type(){

}


sub
usage(){
        while(<DATA>){
               print;
        }
}


sub
select_type(){
my @datatype = ("int",
	     "text",
	     "date",
	     "varchar(256)",
	     "varchar(16)",
	     "varchar(1)",
	     "blob"
	);

my $idx;
for ( $idx = 0; $idx <= $#datatype; $idx++ ){
	print "[$idx] : $datatype[$idx]\n";
}
my $choice = &prompt("Select type: ");
return $datatype[$choice];
}


sub
generate_table_xml($){

my $table_name;

if ( $_[0] eq "") {
	$table_name = &prompt("Table name: ");
}else {
	$table_name = $_[0];
}

my $input;
my $action_performed=0;

my %table_attributes;

my $field_name;
my $field_type;

while($input ne 0){


&menu_table();
$input = &prompt("Selection: ");

if ( "1" eq $input ){
#add a field to table
 	$field_name = &prompt("Field name:");
 	#$field_type = &prompt("Field type:");
	#$table_attributes{"$field_name"} =  $field_type;
	$table_attributes{"$field_name"} =  &select_type();
	$action_performed++;	
}
if ( "2" eq $input ){
#delete a field from table

 	$field_name = &prompt("Field name (to delete):");
	delete( $table_attributes{"$field_name"});
	$action_performed++;	
}
if ( "3" eq $input ){
# save table
	my $tabledata;
	my $fname = "table_".$table_name . ".xml";
	open(F, ">", $fname);
	my %dumptable; 
	$dumptable{"$table_name"} = %table_attributes;
	#$tabledata = &dump_xml_string($table_name, \%table_attributes);
	$tabledata = &dump_xml_string($table_name, \%dumptable);
	print F  $tabledata;
	close(F);
	$action_performed++;	
}
if ( "4" eq $input ){
# save table and EXIT
	my $tabledata;
	my $fname = "table_".$table_name . ".xml";
	open(F, ">", $fname);
	$tabledata = &dump_xml_string($table_name, \%table_attributes);
	print F  $tabledata;
	close(F);
	$action_performed++;	
	$input = "0"; # exit from main loop
}
if ( "9" eq $input ){
# preview xml
	&dump_xml($table_name, \%table_attributes);
	$action_performed++;	
}
if ( $action_performed == 0 ){
        &usage();
}
#&dump_xml($table_name, \%table_attributes);
}#while
}

sub
menu_table(){
print "[0] exit\n";
print "[1] add field\n";
print "[2] delete field\n";
print "[3] save table\n";
print "[4] save table and exit\n";
print "[9] preview xml\n";

}




####
1;
