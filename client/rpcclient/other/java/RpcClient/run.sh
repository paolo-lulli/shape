#! /bin/sh 

BASE=$(dirname $0)
CLASSPATH=$CLASSPATH:$BASE/lib/xmlrpc-client-3.1.2.jar
CLASSPATH=$CLASSPATH:$BASE/lib/ws-commons-util-1.0.2.ja
CLASSPATH=$CLASSPATH:$BASE/lib/xmlrpc-common-3.1.2.jar
CLASSPATH=$CLASSPATH:.

java -cp bin RpcClient
