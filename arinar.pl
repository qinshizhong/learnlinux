#!/usr/bin/perl
#arinar.pl - shows use of arrays
#
@days_between = ("Wed", "Thu");
@days = (Mon, Tue, @days_between, Fri);
@days[5,6] = qw/Sat Sun/;
$length = @days;
#
print("The third day of the week is $days[2]\n");
print("The days of the week are @days\n");
print("The number of elements in the array is $length\n");
print("The last subscript of the array is $#days\n");
$#days = 5;
print("\$days[6] is now $days[6]\n");
