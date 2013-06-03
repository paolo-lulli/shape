#!  /usr/bin/perl

use strict;

#use lib qw(diary);
use diary;



my %whc;
$whc{'created'} = "omment";
my %values_to_update;
$values_to_update{'created'} = "A";
$values_to_update{'comment'} = "B";
$values_to_update{'data'} = "C";


&update_diary_equals("diary", \%values_to_update, \%whc );
