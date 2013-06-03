#! /bin/sh

FBCMD_CONF_DIR="/Users/paolo/code/hb3/default/server-res/resources/FbcmdInterface/module/data/hackbook"
FBCMD_EXE="php /Users/paolo/code/hb3/default/server-res/resources/FbcmdInterface/module/fbcmd/fbcmd.php"

export FBCMD=$FBCMD_CONF_DIR
#$FBCMD_EXE AUTH CSD0O8 # The first time ...
$FBCMD_EXE whoami
