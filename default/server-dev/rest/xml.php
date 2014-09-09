<?php

$name = "somestring";
$size = 11.45;
$xml = '
<xml>
 <name>somestring</name>
  <size>11.45</size>
  </xml>';

   
   $xmlget = simplexml_load_string($xml);

   echo (float)$size*2;   // 22.90
   ?>
