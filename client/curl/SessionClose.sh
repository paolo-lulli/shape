#! /bin/bash -x

USERNAME=root

LOGOFF_URL="http://open.lulli.net/gestionale/logoff.php"

curl -b cookies_$USERNAME.txt  $LOGOFF_URL
