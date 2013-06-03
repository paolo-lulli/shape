#! /bin/sh -x

# Paolo Lulli 2007

#
#  Launch <sql-file> SQL commands
#

source ../../Environment.sh

if [ $# != 1 ]; then
	echo "Use: $0 <sql-file>"
else
	cat $1 | mysql -u $DB_USER  $DB_INSTANCE -p
fi
