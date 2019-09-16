CreateDatabase()
{
	echo "Enter name of database : "
	read filename
	touch $filename
	echo "Database Created / Opened Successfully !"
}

AddRecord()
{
	echo "Enter details of patient : "
	echo "Enter patient name : "
	read name
	echo "Enter patient id : "
	read pid
	echo "Enter patient phone number                                "                                                                                     
	read phno
	echo "Enter patient address : "
	read adrs
	echo "Enter patient type : "
	read ptype
	
	echo "$pid $name $phno $adrs $ptype	" >> "$filename"

}

SearchRecord()
{
	echo "Enter id of patient to be searched : "
	read pname
    num=`grep -c -w "$pname" "$filename"`
	echo num=$num
	if [ $num -eq 0 ]
	then
		echo "Sorry!!!... Record not found in database"
	else
		grep "$pname" -w "$filename"
	fi
}

DeleteRecord()
{
	echo "Enter id of patient to be deleted : "
	read pid
	touch temp
	grep -v -w $pid $filename >> temp #-v - other,-w - same pattern
	mv temp $filename
}

ModifyRecord()
{
	echo "Enter id of patient whose details are to be modified : "
	read pid
	ch=1
	num=`grep -c -w "$pid" "$filename"`
	if [ $num -eq 0 ]
	then
		echo "Sorry!!!... Record not found in database"
	else
	
	while ! [ $ch -eq 5 ]
	do
	
		line=$(grep -h -w $pid $filename)
		name=$(echo $line | cut -d' ' -f2) 
		phno=$(echo $line | cut -d' ' -f3)
		adrs=$(echo $line | cut -d' ' -f4)
		ptype=$(echo $line | cut -d' ' -f5)
	
		echo "Enter attribute to be modified : /n1)Name of patient /n2)Address /n3)Phone Number /n4)Patient Type"
		read ch
		case $ch in
			1)echo "Enter new name of patient : "
				read name;;
			2)echo "Enter new address of patient : "
				read adrs;;
			3)echo "Enter new phone number of patient : "
				read phno;;
			4)echo "Enter new patient type : "
				read ptype;;
			*)echo "Enter valid choice";;
		esac
	done
	
	touch temp
	grep -v -w $pid $filename >> temp
	mv temp $filename
	echo "$pid $name $phno $adrs $ptype" >> "$filename"	
	
	fi	 
}

filename="patient"
choice=1

while ! [ $choice -eq 7 ]
do

echo "MENU :  \n1)Create Database\n2)Add Record \n3)Search Record \n4)Delete Record \n5)Display Database \n6)Modify Record \n7)EXIT \nEnter your choice : "
read choice

case $choice in
	1)echo "Create Patient Database"
	  CreateDatabase;;
	2)echo "Adding  a Record"
	  AddRecord;;
	3)echo "Searching Record"
	  SearchRecord;;
	4)echo "Deletion Record"
	  DeleteRecord;;
	5)echo "Displaying Database"
	  cat $filename;;
	6)echo "Modifying Record"
	  ModifyRecord;;
	7)echo "EXITING...";;
	*)echo "Enter valid choice";;
esac
done
