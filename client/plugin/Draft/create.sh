#! /bin/sh

cd $(dirname $0)

../../rpcclient/rpcrud -C                   \
		-t "draft"                  \
		-T "varchar(256),text,date" \
		-f "ID,note,date"           \
		-x
