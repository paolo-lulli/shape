#! /bin/sh

if [ "$#" == 0 ]; then 
	echo "Zero args detected, exiting"
	exit -1;
fi
if [ "$#" == 1 ];then
	ID=$(uuidgen)
	input=$1 
	if [ -f $input ]; then
		#cat $input | openssl enc -base64 
		BASE64_url=$(cat $input | openssl enc -base64)
		BASE64_description=$(cat $input | openssl enc -base64)
		#echo "$BASE64_note" | while read line; do echo "Processing $line"; done
		echo "$BASE64_note" 
	else 
		echo "File $input is not valid"
		exit -1
	fi
fi

date=$(date)



../../rpcclient/rpcrud -I -t "links" -T text,text,text -f ID,url,description -v"$ID,$BASE64_url,$BASE64_description"  -dA
