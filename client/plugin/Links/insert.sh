#! /bin/sh

ID=$(uuidgen)
echo "Insert url:"
read url
echo "Insert description:"
read description

../../rpcclient/rpcrud -I -t "links" -T text,text,text -f ID,url,description -v"$ID,$url,$description"  -x
