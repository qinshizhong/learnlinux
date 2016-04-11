# /bin/bash

answer=y
while [ "$answer" = "y" ]
do
	echo "Enter the code and description:" > /dev/tty
	read code description
	echo "$code|$description"
	echo "Enter any more (y/n)?" >> /dev/tty
	read anymore
	case $anymore in
		y*|Y*) answer=y;;
		n*|N*) answer=n;;
		*) answer=y;;
	esac
done > newlist
