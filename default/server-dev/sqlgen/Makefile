all:	database.sql

database.sql:	output.xsl database.xml
	xsltproc  output.xsl database.xml > database.sql
