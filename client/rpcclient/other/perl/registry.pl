#! /usr/bin/perl
#
use Frontier::Client;
use Data::Dumper;

$server_url = 'http://localhost:8001/hb/www/gw/rpc.php';
$server_url = 'http://localhost/hb/gw/rpc.php';

$server = Frontier::Client->new(url => $server_url);

$result = $server->call('registry.get', '9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5');

%registry = %{$result};
print Dumper($result);
#print $result;

print "role : ".  $registry{'9D5E4FEF-062E-47E2-BBB3-7F21C7DE96D5'}{'role'};
#print $result;
