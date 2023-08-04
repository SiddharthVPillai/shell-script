#!/bin/bash

echo "Menu:"
echo "1. Create Employee Record
2. Delete Employee Record
3. Search Employee Record
4. Display Employee Details
5. Sort Record
6. List All  Record
7. Exit
Enter your choice (1-7):"

read option

echo "your option is $option"

case $option in
	1)	echo "Enter employee name: "
		read emp_name
		echo "Enter employee number: "
		read emp_no
		echo "Enter telephone number: " 
		read tel_no

		echo "$emp_name : $emp_no : $tel_no " >> data
		;;

	*)	echo "Wrong option"
		;;
esac
