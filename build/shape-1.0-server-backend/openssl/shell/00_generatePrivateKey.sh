#! /bin/sh -x

source Env.sh
openssl genrsa -des3 -out $PRIVATE_KEY_FILE 1024

