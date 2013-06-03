#! /bin/sh

java  -jar schemaSpy_5.0.0.jar  -cp jdbc/mysql-connector-java-3.0.10-stable-bin.jar -t mysql   -db hbf00 -s hbf00 -u hbf00 -p hbf00 -host localhost  -o ../doc/schemaDb
