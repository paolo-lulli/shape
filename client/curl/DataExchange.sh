#! /bin/bash -x

USERNAME=root

DATA_URL="http://open.lulli.net/gestionale/index.php"

curl -b cookies_$USERNAME.txt  $DATA_URL
