#!/usr/bin/perl
# script: input.pl - shows use of subroutines
#
system("tput clear");
$username = &take_input("Oracle user-id: ");
$password = &take_input("Oracle password: ", "noecho");
print "\nThe user name and password are $username and $password\n";

sub take_input {
    my ($prompt, $flag) = @_;
    while (1) {
        print("$prompt");
        system("stty -echo") if (@_ == 2);
        chop($name = <STDIN>);
        system("stty echo") if (@_ == 2);
        last if $name =~ /\w/;
    }
    $name;
}

