#!/bin/bash

create()
{
	echo "Enter the number of records :: "
	read no
	
	while [ true ];
	do
		if [ $no -eq 0 ]; then
			break
		fi
		
		insert
		
		no=$((no-1))
	done
}

insert()
{
	echo "Enter details ::\n"

	while [ true ];
	do

		echo "Enter id :: "
		read Id

		grep -q "$Id	" "$filename"
		check=`echo $?`
		
		if [ $check -eq 1 ]; then
			break;
		else
			echo "Enter Id again, dont input duplicate id!!"
		fi

	done

	echo "Enter name :: "
	read name
	echo "Enter contact no :: "
	read contact
	echo "Enter car model purchased :: "
	read carModel
	echo "$Id\t$name\t$contact\t$carModel">>"$filename"

}

display()
{
	echo "ID\tNAME\tCONTACT NO\tCAR MODEL\n"
	sort -k 1 $filename > temp.txt
	mv temp.txt "$filename"
	cat $filename
	
}

search()
{
	echo "Enter id you want to serach :: "
	read field
	
	grep -w "$field" "$filename"
	ret=`echo $?`
	
	if [ $ret -eq 1 ]; then
		echo "Record not found!!"
	else
		echo "Record found!!"
	fi
		
}

delet()
{
	echo "Enter id you want to delete :: "
	read field
	grep "$field" "$filename"
	check=`echo $?`
	if [ $check -eq 1 ]; then
		echo "Record not found!!"
	else
		grep -v "$field" "$filename" > temp.txt
		mv temp.txt "$filename"
		echo "Record deleted"
		echo "\nID\tNAME\tCONTACT NO\tCAR MODEL\n"
		cat "$filename"
	fi
}

modify()
{
	echo "Enter name you want to update :: "
	read name
	grep -n "$name" "$filename"
	check=`echo $?`
	if [ $check -eq 1 ]; then
		echo "Record not found!!"
	else
		echo "Enter the line number (the first number of the entry) that you'd like to edit."
		read lineNumber
		
		for line in `grep -n "$name" "$filename"`
		do
			number=`echo $line | cut -c1`

			if [ $number -eq $lineNumber ]; then
				echo "Enter updated record :: "
				read newRecord
				lineChange="${lineNumber}s"
				echo "\nID\tNAME\tCONTACT NO\tCAR MODEL\n"
				sed -i -e "$lineChange/.*/$newRecord/" "$filename"
				echo "Record updated!!"
			fi

		done
	fi	
}



echo "\n*********CAR MANUFACTING COMPANY**********\n"

echo -n "Enter filename to create :: "
read filename

if [ ! -e $filename ]; then
	echo "Creating file"
	touch $filename
else
	echo "File already present"
fi

while [ true ];
do
	echo "\n::MENU::"
	echo "1.Create database"
	echo "2.Insert record"
	echo "3.Display database"
	echo "4.Delete record"
	echo "5.Search record"
	echo "6.Modify record"
	echo "7.Exit"
	echo -n "Enter choice :: "
	
	read choice
	
	case $choice in
	
	1)
		create
		;;
	2)
		insert
		;;
	3)
		display
		;;
	4)
		delet
		;;
	5)
		search
		;;
	6)
		modify
		;;
	7)
		exit
		;;
	*)
		echo "Invalid choice, enter choice again\n"
		;;
	
	esac
	
done
