#! /bin/bash

#valcode.sh: Uses a here document to look up a code list
#

IFS="|"
while echo -e "Enter department code:\c"
do
	read dcode
	set -- `egrep "$dcode" << mark
	01|accounts|6213
02|admin|5243
03|marketing|6521
04|personnel|2365
05|production|9876
06|sales|1006
mark`
	case $# in
		3) echo -e "Department name : $2\012Emp-id of head of dept:$3\012"
		   shift 3;;
		*) echo "Invalid code"; continue;;
	esac
done
