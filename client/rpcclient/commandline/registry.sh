#! /bin/sh 

CURRDIR=$(dirname $0)
cd $CURRDIR
echo "Username:"
read username

echo "Password:"
read password

php cmdclient.php --username=$username --password=$password
