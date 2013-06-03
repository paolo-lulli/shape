#! /bin/sh -x

CONFIG_DIR="."
TABLE=$1
TABLE_TEMPLATE="table_"$TABLE".xml"


xsltproc create.xsl $TABLE_TEMPLATE #> myshell.sh 
