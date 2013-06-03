#! /usr/bin/perl

use Digest::SHA1  qw(sha1 sha1_hex sha1_base64);

my $sha = sha1_hex('admin');
print "$sha\n";
