#! /bin/sh -x

cc hb_client.c -L/usr/local/lib /usr/local/lib/libxmlrpc-epi.dylib -o hb_client
