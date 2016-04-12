#!/usr/bin/perl
#script: sample.pl - Shows use of variables
#
print("Enter your name:");
$name = <STDIN>;
print("Enter a temperature in Centigrade:");
$centigrade = <STDIN>;
$fahrenheit = $centigrade * 9 / 5 + 32;
print "The temperature $name in Fahrenheit is $fahrenheit\n"
