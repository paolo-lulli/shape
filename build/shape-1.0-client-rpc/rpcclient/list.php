<?php
	include("../../www/gw/mapping.inc");
	echo "\n";
	echo "Published Rpc Services:";
	echo "\n";
	echo "----------------------";
	echo "\n";
	foreach ( $api_mapping as $t ){
		echo $t . "\n";
	}
?>
