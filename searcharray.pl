#!/usr/bin/perl
# script: searcharay.pl - search array for a string or regular expression
#
@dept_arr = <>
for ($i = 0; $i < 3; $i++) {
    print("Enter a code to look up: ");
    chop($code = <STDIN>);
    @found_arr = grep(/^$code/, @dept_arr);
    if ($#found_arr == -1 || $code eq "") {
        print("Code does not exist\n");
        next;
    }
    split(/\|/, $found_arr[0]);
    print("Code = $code    Description = $_[1]\n");
}
