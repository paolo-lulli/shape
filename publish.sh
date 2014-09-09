#! /bin/sh

#LOCAL_DIR=ReactReader
WEBDIR=/home2/dbthunde/public_html/src/dist/shape
WEBUSER=dbthunde
WEBHOST=dbthunder.com

###############################################

source ./build.cfg
#PROJECT="hbf"
#VERSION="1.0"

hbf_targz_backend=$PROJECT-$VERSION-server-backend.tar.gz
hbf_targz_frontend=$PROJECT-$VERSION-server-frontend.tar.gz
hbf_targz_gateway=$PROJECT-$VERSION-server-gateway.tar.gz

make -f Makefile dist

SYNC_TYPE=rsync

scp ./dist/packages/$hbf_targz_backend 		$WEBUSER@$WEBHOST:$WEBDIR
scp ./dist/packages/$hbf_targz_frontend 	$WEBUSER@$WEBHOST:$WEBDIR
scp ./dist/packages/$hbf_targz_gateway 		$WEBUSER@$WEBHOST:$WEBDIR

