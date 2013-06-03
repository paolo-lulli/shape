#! /bin/sh 

# Paolo Lulli 2007

#
# Crea la/le tabelle "core"
# (lancia tutti gli sql contenuti in ./sql/ )
#
#

. ../Environment.sh

#plg_report

for i in $( ls -1 sql/*.sql); do
	if [ -f $i ]; then
	echo "Launching $i"
	cat "$i" | mysql -u $DB_USER  $DB_INSTANCE -p
	fi
done


