#! /usr/bin/perl
#
use Frontier::Client;
use Data::Dumper;

# Make an object to represent the XML-RPC server.
#$server_url = 'http://localhost:8001/hb/www/rpc/XRPC/XRPC_Server_Test.php';
#$server_url = 'http://localhost/hb/ws/XRPC_Server_Test.php';
#$server_url = 'http://localhost/hb/gw/rpc.php';
$server_url = 'http://localhost:8001/hb/www/gw/rpc.php';
$server_url = 'http://localhost/hb/gw/rpc.php';
#$server_url = 'http://xmlrpc-c.sourceforge.net/api/sample.php';
$server = Frontier::Client->new(url => $server_url);

###########################$result = $server->call('test.connection', 5, 3);
#$result = $server->call('test.connection', 5, 3);
######## [TODO]      
$result = $server->call('user.getnick', '9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5');
#$result = $server->call('user.getnick', "3BCA1094-9B6B-4452-9B64-8C3FF445D7BE");
#$sum = $result->{'sum'};
#$difference = $result->{'difference'};

#print Dumper($result);
print $result;
#print "Sum: $sum, Difference: $difference\n";
