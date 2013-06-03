<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN"
    "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xml:lang="it" xmlns="http://www.w3.org/1999/xhtml" lang="it">
<head>
<title><?= $page['title'] ?></title>
<meta http-equiv="Content-Type" content="text/html;charset=utf-8" />
<meta name="Keywords" content="$KEYWORDS" />
<!--
<link href="color_blocks.css" rel="stylesheet" type="text/css" />
-->
<link href="./css/hackbook.css" rel="stylesheet" type="text/css" />
<!--
<link href="./css/effects.css" rel="stylesheet" type="text/css" />
-->
<link href="./css/layout-3col-float.css" rel="stylesheet" type="text/css" />
</head>


<body>
<!--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ -->

<div id="container">
<div id="header"><?= $page['header'] ?></div>

<div id="menu"><?= $page['menu'] ?></div>

<div id="navigation"><?= $page['navigation'] ?></div>
<div id="main"><?= $page['main'] ?> </div>


<!--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ -->
<div class="clearfooter"></div>
<div id="footer"><?= $page['footer'] ?></div>
</div><!-- container closes before footer -->
<!--++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ -->
</body>
</html>




