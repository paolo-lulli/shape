<?php
	include ("../www/settings.inc");
	$conn_string = "sqlite:" . DB_FILE;
//	$conn_string = "sqlite:/home/paolo/code/hb/db/webauth.db";
try {
    /*** connect to SQLite database ***/
    //$dbh = new PDO("sqlite:".DB_FILE);
    $dbh = new PDO($conn_string);
       echo 'Connected to database'. "\n";
    
    $sql = "SELECT * FROM User";
    foreach ($dbh->query($sql) as $row)
        {
        print $row['ID'] .' - '. $row['name']. "\n";
        }
    }
catch(PDOException $e)
    {
    echo $e->getMessage();
    }
?>
