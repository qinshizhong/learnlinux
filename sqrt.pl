#!/usr/bin/perl
# sqrt.pl - finds the square root of each command line argujent.
#
print("The program you are running is $0\n");
foreach $number (@ARGV) {
    print("The square root of $number is ", sqrt($number) . "\n");
}
