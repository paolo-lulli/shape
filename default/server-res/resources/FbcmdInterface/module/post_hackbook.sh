#! /bin/sh -x

FBCMD_CONF_DIR="/Users/paolo/code/hbf/default/server-res/resources/FbcmdInterface/module/data/hackbook"
FBCMD_EXE="php /Users/paolo/code/hbf/default/server-res/resources/FbcmdInterface/module/fbcmd/fbcmd.php"

export FBCMD=$FBCMD_CONF_DIR
echo "Write your post "
read MYPOST
$FBCMD_EXE FEED1 "$MYPOST"
