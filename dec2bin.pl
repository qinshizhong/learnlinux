#!/usr/bin/perl
# script: dec2bin.pl - converts decimal numbers to binary
#
foreach $number (@ARGV) {
    $original_number  = $number;
    until ($number == 0) {
        $bit = $number % 2;
        unshift(@bit_arr, $bit);
        $number = int($number / 2);
    }
    $binary_number = join("", @bit_arr);
    print("The binary number of $original_number is $binary_number\n");
    $#bit_arr = -1;
}

