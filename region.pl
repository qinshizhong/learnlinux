#!/usr/bin/perl
# scription: region.pl - uses an associative array
#
%region = ("N", "North", "S", "South", "E", "East", "W", "West");
foreach $letter (@ARGV) {
    print("The letter $letter stands for $region{$letter}\n");
}
@key_list = keys(%region);
print("The subscripts are @key_list\n");
@value_list = values(%region);
print("The values are @value_list\n");
