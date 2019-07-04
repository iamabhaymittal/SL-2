#!/bin/bash
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
NC='\033[0m'

clear
echo "Enter the name of file you want to use for storing data:"
			read file
			if [ -e $file ]
			then
			   echo "File already exists. Over-writing file $file"
			else
			   touch $file
			fi


while [ 1 -lt 2 ] 
do
	
	echo
	echo
	echo -e "${YELLOW}===================================="
	echo -e "${BLUE}             M E N U"
	echo -e "${YELLOW}====================================${NC}"
	echo  "1. Create a new file for Database"
	echo  "2. View address book"
	echo  "3. Insert a record"
	echo  "4. Delete a record"
	echo  "5. Modify a record"
	echo  "0. Exit"
	echo -e "${YELLOW}====================================${NC}"
	
	echo -n "Enter your choice:"
	
	read ch
	case $ch in 
		1) 
			echo "Enter the name of file you want to use for storing data:"
			read file
			if [ -e $file ]
			then
			   echo "File already exists. Adding records to $file"
			else
			   touch $file
			fi
			;;
		2) 
			cat $file
			
			;;
		3) 
			echo "Enter ID Number:"
			read id_no
			echo "Enter Name:"
			read name
			echo "Enter Gender:"
			read gender
			echo "Enter Department:"
			read dept
			echo "Enter Class:"
			read class
			echo "$id_no $name $gender $dept $class">>$file
			
			;;
			
		4)
			
			
			;;	
		
		5)
			
			
			;;
		0)
			echo -e "${RED}Thank You!${NC}"
			break ;;
	esac
	
done

