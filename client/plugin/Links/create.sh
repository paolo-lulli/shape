#! /bin/sh

../../rpcclient/rpcrud -C -t "links" -T "varchar(256),text,text" -f "ID,url,description"  -x
