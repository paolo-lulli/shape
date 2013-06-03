#! /bin/sh -x

cc hb_client.c -L/usr/lib /usr/lib/libxmlrpc.so -o hb_client
