#! /usr/bin/perl

use Data::Dumper;
require RPC::XML;
    require RPC::XML::Client;

    $cli = RPC::XML::Client->new('http://hb.lulli.net/gw/rpc.php');
    $resp = $cli->send_request('test.connection');

#    print (ref $resp) ? join(', ', @{$resp->value}) : "Error: $resp";
print Dumper($resp);
