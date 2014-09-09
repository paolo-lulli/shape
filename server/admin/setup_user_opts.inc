<?php

$shortopts  = "";
$shortopts .= "n:";  //name
$shortopts .= "s:";  //surname
$shortopts .= "N:";  //NICKname
$shortopts .= "e:";  //email
$shortopts .= "p:";  //password

$longopts  = array(
    "name:",     // Required value
    "surname:",     // Required value
    "nickname:",     // Required value
    "email:",     // Required value
    "password:"     // Required value
);
$options = getopt($shortopts, $longopts);

if (isset($options["name"])){
        $name = $options["name"];
} else if (isset($options["n"])){
        $name = $options["n"];
} else {
        echo "Missing name\n";
exit;
}




if (isset($options["surname"])){
        $surname = $options["surname"];
} else if (isset($options["s"])){
        $surname = $options["s"];
} else {
        echo "Missing surname\n";
exit;
}
 

if (isset($options["nickname"])){
        $nickname = $options["nickname"];
} else if (isset($options["N"])){
        $nickname = $options["N"];
} else {
        echo "Missing nickname\n";
exit;
}
 
if (isset($options["email"])){
        $email = $options["email"];
} else if (isset($options["e"])){
        $email = $options["e"];
} else {
        echo "Missing email\n";
exit;
}
 
if (isset($options["password"])){
        $password = $options["password"];
} else if (isset($options["p"])){
        $password = $options["p"];
} else {
        echo "Missing password\n";
exit;
}
 



echo $options["n"];

?>

