#! /bin/sh 
#
# PL2010


if [ $# == 1 ]; then
	resource_name=$1;
else
	echo "Insert resource_name";
	read resource_name;
fi
echo "Processing resource: [$resource_name]"

if [ ! -d "$resource_name" ]; then
	cd resources
	mkdir $resource_name
	cd $resource_name

cat <<_EOT_>data.inc
<?php
/*
        Here you put custom 'plugin' variables
	*/

	\$var1 ="try 1";
	\$var2 ="try 2";
	\$resname="$res_name";

?>
_EOT_

cat <<_EOT_>display.inc
<?php

echo "<b>This is the displayed [\$resname] block</b>";

?>
_EOT_

cat <<_EOT_>setup.inc
<?php

\$res_name="$resource_name";
\$res[\$res_name]['type']="include.block";
\$res[\$res_name]['description']="__Edit this description__";
\$res[\$res_name]['externaltable']="RES_$resource_name";
\$res[\$res_name]['data']="data.inc";
\$res[\$res_name]['internal']="0";

/*
\$res_name="zero";
\$res[\$res_name]['type']="include.block";
\$res[\$res_name]['description']="__Edit this description__";
\$res[\$res_name]['externaltable']="";
\$res[\$res_name]['data']="data.inc";
\$res[\$res_name]['internal']="1";
*/




?>
_EOT_

mkdir module
cd module
mkdir control view model;


app=$resource_name"Model"
cat <<_EOT_>model/$resource_name\Model.class.inc
<?php

class $app
{

}
?>

_EOT_

app=$resource_name"Control"
cat <<_EOT_>control/$app.class.inc
<?php

class $app extends GenericControl
{
        public function execute(){
                return date("s M Y");
        }
}
?>
_EOT_


cat <<_EOT_>control/$resource_name\_operation.inc
<?
        include ("$app.class.inc");
        \$c = new $app;
        echo \$c -> execute(); //TODO change method name to the chosen one
?>

_EOT_

app_name=$resource_name"name"
app_msg=$resource_name"msg"
cat <<_EOT_>control/$resource_name\.js

Ext.onReady(function(){
        //Ext.get('okButton').on('click', function(){
        Ext.get('$app_name').on('change', function(){
                var msg = Ext.get('$app_msg');
                msg.load({
                        url: 'call.php', // <-- change if necessary
                        params: 'name=' + Ext.get('name').dom.value,
                        text: 'Updating...'
                });
                msg.show();
        });
});
_EOT_



app_name=$resource_name"name"
app_msg=$resource_name"msg"
cat <<_EOT_>view/view$resource_name.php
<div>
    Name: <input type="text" id="$app_name" />
        <!-- <input type="button" id="okButton" value="OK" />-->
        </div>
        <div id="$app_msg"></div>
_EOT_

else 

echo "Error: dir [$resource_name] already exists"

fi

