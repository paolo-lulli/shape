#! /bin/sh 

UNAME=$(uname -s)

if [ "$UNAME" == "Linux" ]; then
	PHP_EXE="/opt/lampp/bin/php"
fi

if [ "$UNAME" == "Darwin" ]; then
	PHP_EXE="/Applications/XAMPP/xamppfiles/bin/php"
fi
if [ "$UNAME" == "FreeBSD" ]; then
        PHP_EXE="/usr/local/bin/php"
fi


if [ "$PHP_EXE" == "" ]; then
	PHP_EXE=$(which php);
fi


CURRDIR=$(dirname $0)
cd $CURRDIR

cd ./src
$PHP_EXE create.php "$@"
