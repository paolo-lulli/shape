<?php

if (! empty($_REQUEST['logoff'])){
	$is_logging_off = 1;
}

#var_dump($is_logging_off);
if ($is_logging_off == 1)  {
        include("logoff.inc");
        #$is_logging_off++ ;
} else {
        #include("login_form.inc");
        #include("login.inc");
        if ( ! empty($_SESSION['USER'])){
                include("user_infos.php");
        }
}
?>
