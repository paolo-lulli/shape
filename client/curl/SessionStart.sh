#! /bin/bash -x

USERNAME=root
PASSWORD=root

LOGIN_URL="http://open.lulli.net/gestionale/login.php"

curl -c cookies_$USERNAME.txt  -d"username=$USERNAME&password=$PASSWORD" $LOGIN_URL
