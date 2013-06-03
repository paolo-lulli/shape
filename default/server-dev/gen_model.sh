#! /bin/sh

cd crud

for i in ../model/*; do 
	echo ""
	echo ""
	echo "----------------------------------"
	echo "Processing [$i]";
	echo "----------------------------------"
	./crud.pl "$i";
done 
