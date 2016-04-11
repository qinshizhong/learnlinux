#!/bin/bash

./foo.sh << MARK
1
MARK
echo "		MENU\n
1. List of files^J2. Processes of user\n3. Today's Date
4. Users of system\n5. Quit to Unix\nyour option:\c"
read choice
case $choice in
	1) ls -l;;
	2) ps -f;;
	3) date;;
	4) who;;
	5) exit;;
	*) echo Invalid option;;
esac
