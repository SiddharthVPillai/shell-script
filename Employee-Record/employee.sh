#!/bin/bash
function menu(){
echo "Menu:"
echo "1. Create Employee Record
2. Delete Employee Record
3. Search Employee Record
4. Display Employee Details
5. Sort Record
6. List All  Record
7. Exit"
}

function create(){
	clear
	read -p "Enter employee name: " name
	read -p "Enter employee number: " eno
	read -p "Enter contact number: " cno

	if grep -q "^.*:$eno:.*$" employee_data.txt; then
		echo "Employee already exists"
	else
		echo "$name:$eno:$cno" >> employee_data.txt
		echo "----Employee added successfully----"
	fi
}

function remove(){
	clear
	read -p "Enter the employee number: " eno
	grep -v "^.*:$eno:.*$" employee_data.txt > temp.txt
	mv temp.txt employee_data.txt
	echo "----Record deleted successfully----"
}

function search(){
	clear
	read -p "Enter the employee number you want to search: " eno
	echo --------
	grep "^.*:$eno:.*$" employee_data.txt
}

function list(){
	clear
	echo --------------
	cat employee_data.txt
	echo --------------
}

function sort_data(){
	sort -t ':' -k2n employee_data.txt > temp.txt
	mv temp.txt employee_data.txt
	clear
	echo "----Record Sorted Successfully----"
}

while true;
do
	menu
	read -p "Enter choice: " choice
	case $choice in
		1)
			create
			;;
		2)
			remove
			;;
		3)
			search
			;;
		4)
			search
			;;
		5)
			sort_data
			;;
		6)
			list
			;;
		7)
			exit 0
			;;
		*)
			echo "Invalid choice"
			;;
	esac
	echo
done
