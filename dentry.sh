#!/bin/bash

#dentry.sh: Data entry script - Runs in loop
#

trap 'echo Not to be interrupted' INT
trap 'echo Signal received; exit' HUP TERM
file=desig.lst
while echo -e "Designation code:\c" > /dev/tty
do
	read desig
	case "$desig" in
	[0-9][0-9]) if egrep "^$desig" $file > /dev/null; then
			echo Code exits
			continue
		    fi;;
	*) echo Invalid code
		continue;;
	esac

	while echo -e "Description:\c" > /dev/tty
	do
		read desc
		case "$desc" in
		*[!\ a-zA-Z]*) echo "Can contain only alphabets and spaces" > /dev/tty
		continue;;
		"") echo "Description not entered" > /dev/tty
			continue;;
		*) echo "$desig|$desc"
			break;;
		esac
	done > $file
	
	echo -e "\nWish to continue? (y/n):\c"
	read answer
	case "$answer" in
	[yY]*) continue;;
	*) break;;
	esac
done

echo "Normal exit"
