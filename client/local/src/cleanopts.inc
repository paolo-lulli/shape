<?php

$opt[0]['SHORT']='G';
$opt[0]['LONG']='generate';
$opt[0]['DESCRIPTION']='Generate';

$opt[1]['SHORT']='I';
$opt[1]['LONG']='insert';
$opt[1]['DESCRIPTION']='Insert';

$opt[2]['SHORT']='C';
$opt[2]['LONG']='create';
$opt[2]['DESCRIPTION']='Create';

$opt[3]['SHORT']='R';
$opt[3]['LONG']='read';
$opt[3]['DESCRIPTION']='Read (Select)';

$opt[4]['SHORT']='U';
$opt[4]['LONG']='update';
$opt[4]['DESCRIPTION']='Update';

$opt[5]['SHORT']='D';
$opt[5]['LONG']='delete';
$opt[5]['DESCRIPTION']='Delete';

$opt[6]['SHORT']='f:';
$opt[6]['LONG']='fields:';
$opt[6]['DESCRIPTION']='Fields';

$opt[7]['SHORT']='v:';
$opt[7]['LONG']='values';
$opt[7]['DESCRIPTION']='Values';

$opt[8]['SHORT']='V:';
$opt[8]['LONG']='where_values:';
$opt[8]['DESCRIPTION']='where_values';

$opt[9]['SHORT']='F:';
$opt[9]['LONG']='where_fields:';
$opt[9]['DESCRIPTION']='Where fields';

$opt[10]['SHORT']='a:';
$opt[10]['LONG']='aliases:';
$opt[10]['DESCRIPTION']='Aliases';

$opt[11]['SHORT']='t:';
$opt[11]['LONG']='table:';
$opt[11]['DESCRIPTION']='Table';

$opt[12]['SHORT']='T:';
$opt[12]['LONG']='types';
$opt[12]['DESCRIPTION']='types';

$opt[12]['SHORT']='c:';
$opt[12]['LONG']='columns';
$opt[12]['DESCRIPTION']='Columns';

$opt[13]['SHORT']='d';
$opt[13]['LONG']='debug';
$opt[13]['DESCRIPTION']='Delete';

$opt[14]['SHORT']='x';
$opt[14]['LONG']='xmlrpc';
$opt[14]['DESCRIPTION']='xmlrpc';

$opt[15]['SHORT']='p';
$opt[15]['LONG']='plain';
$opt[15]['DESCRIPTION']='plain';

$opt[16]['SHORT']='A';
$opt[16]['LONG']='all';
$opt[16]['DESCRIPTION']='DEBUG_ALL together with -d ';

$opt[17]['SHORT']='e';
$opt[17]['LONG']='equals';
$opt[17]['DESCRIPTION']=' = sign ';

$opt[18]['SHORT']='n';
$opt[18]['LONG']='notequals';
$opt[18]['DESCRIPTION']=' != sign ';

$opt[19]['SHORT']='g';
$opt[19]['LONG']='greater';
$opt[19]['DESCRIPTION']=' > sign ';

$opt[20]['SHORT']='l';
$opt[20]['LONG']='lesser';
$opt[20]['DESCRIPTION']=' < sign ';

$opt[21]['SHORT']='L';
$opt[21]['LONG']='like';
$opt[21]['DESCRIPTION']=' To use for select like(EXPRESSION) queries ';






$shortopts="";
$longopts=array();

foreach ($opt as  $iopt ){
	#echo $iopt['LONG'];
	$shortopts.=$iopt['SHORT'];
	array_push($longopts,$iopt['LONG']);
}
$options = getopt($shortopts, $longopts);
var_dump($options);

foreach ($opt as  $iopt ){
	echo "-". $iopt["SHORT"]  . "\t";
	echo "--".$iopt["LONG"]   . "\t\t";
	echo      $iopt["DESCRIPTION"] . "\n";
}

?>
