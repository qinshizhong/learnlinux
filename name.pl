#!/usr/bin/perl
# Script: name.pl - Demonstrates use of chop
#
print("Enter your name: ");
$name = <STDIN>;
chop($name);
if ($name ne "") {
    print("$name, have a nice day\n");
} else {
    print("You have not enter your name\n");
}

