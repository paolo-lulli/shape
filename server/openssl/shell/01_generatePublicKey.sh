#! /bin/sh -x

source Env.sh

openssl rsa -in $PRIVATE_KEY_FILE -pubout -out $PUBLIC_KEY_FILE

