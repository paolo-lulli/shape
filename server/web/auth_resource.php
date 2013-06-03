<?php
$db = new SQLite3(DB_FILE);

/////////////////////////////
//$_REQUEST['USER']="EAD7AF0E-03A2-432F-93DA-9968BF157198";
//$_REQUEST['ROLE']="F6CA9F14-6663-4309-9854-68004D25FBF5";
//$_REQUEST['RESOURCE']="2D733697-F85A-477A-A195-DE3D522F5C95";
/////////////////////////////

$user_id =$_REQUEST['USER'];
$role_id =$_REQUEST['ROLE'];
$resource_id =$_REQUEST['RESOURCE'];

/////////////////////////////

$query = sprintf("select count(*) as authorized from   Account a
join User u on u.ID = a.ID_User
join Usergroup g on g.ID = a.ID_Usergroup
join Role r on  r.ID = a.ID_Role
join Policy p on p.ID_Role = r.ID
where u.ID = '%s'
and   r.ID = '%s'
and   p.ID_Resource = '%s'",
    mysql_real_escape_string($user_id),
    mysql_real_escape_string($role_id),
    mysql_real_escape_string($resource_id));
//echo $query;

// Perform Query
echo "<br/>User ID: ";
echo $_REQUEST['USER']; 
echo "<br/>Role ID: ";
echo $_REQUEST['ROLE']; 
echo "<br/>Resource ID: ";
echo $_REQUEST['RESOURCE']; 
#$results = $db->query('select * from User');
$results = $db->query($query);
while ($row = $results->fetchArray()) {
    echo '<br/>';
    //var_dump($row);
    //echo $row["created"];
    echo "authorized: (1=true, 0=false)";
    echo $row["authorized"];
    echo '<br/>';
}
?>
