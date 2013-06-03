#! /bin/sh

read A
echo -n $A | openssl enc -base64


ID=$(uuidgen)
echo "Insert url:"
read url
echo "Insert description:"
read description

BASE64_url=$(echo -n $url | openssl enc -base64)
BASE64_description=$(echo -n $url | openssl enc -base64)

../../rpcclient/rpcrud -I -t "links" -T text,text,text -f ID,url,description -v"$ID,$BASE64_url,$BASE64_description"  -x

