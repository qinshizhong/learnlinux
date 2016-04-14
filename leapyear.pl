#!/usr/bin/perl
#script: learpyear.pl - determines whether a year is a leap year or not
#
die("You have not entered the year\n") if (@ARGV == 0);
$year = $ARGV[0];
$last2digits = substr($year, -2, 2);
if ($last2digits eq "00") {
    $yesorno = ($year % 400 == 0 ? "certainly" : "not");
} else {
    $yesorno = ($year % 4 == 0 ? "certainly" : "not");
}
print("$year is " . $yesorno . " a leap year\n");
