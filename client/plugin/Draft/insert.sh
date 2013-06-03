#! /bin/sh

cd $(dirname $0)

if [ "$#" == 0 ]; then 
	echo "Zero args detected, exiting"
	exit -1;
fi
if [ "$#" == 1 ];then
	ID=$(uuidgen)
	input=$1 
	if [ -f $input ]; then
		BASE64_note=$(cat $input | openssl enc -base64)
		#echo "$BASE64_note" | while read line; do echo "Processing $line"; done
		echo "$BASE64_note" 
	else 
		echo "File $input is not valid"
		exit -1
	fi
fi

date=$(date '+%Y-%m-%d %H:%M:%S')

../../rpcclient/rpcrud -I -t "draft" -T text,text,text -f ID,note,date -v"$ID,$BASE64_note,$date"  -x -dA
