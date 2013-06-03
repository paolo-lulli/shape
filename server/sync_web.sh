#! /bin/sh -x

cd $(dirname $0);

source ../install/etc/server.cfg

LOCAL_DIR=web
WEBDIR=$REMOTE_WEB_INSTALL_DIR
WEBUSER=$REMOTE_WEB_USER
WEBHOST=$REMOTE_WEB_MACHINE

SYNC_TYPE=rsync


if [ "$SYNC_TYPE" == "rsync" ]; then
	rsync -ar $LOCAL_DIR/* $WEBUSER@$WEBHOST:$WEBDIR
else 
	scp -r $LOCAL_DIR/* $WEBUSER@$WEBHOST:$WEBDIR
fi
