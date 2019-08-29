
#! \bin\bash
count=0
createbook()
{

 	# Name of address book
        BOOK="address-book.txt"

        # Ask the user for a name and assign to a variable
        echo -n "Name of employee: " 
        read name

        # Ask the user for a phone number and assign to a variable
        echo -n "Phone number: "
        read phone

	echo -n "ID of employee: " 
        read id
	echo "$name -- $phone -- $id" >>$BOOK
	((count++))
        echo "Entry/Entries added!"
}


displaybook()
{
	BOOK="address-book.txt" 

        # Display the format before the entries
       # echo "Line Number:   Name  ;  Phone Number"

        # Print the book with line numbers and paused with less
        #nl --number-separator=":    " $BOOK | less
	echo "Name  --  Phone  --  ID"
	cat  address-book.txt
}

searchbook()
{	
	BOOK="address-book.txt"

        # Ask the user what to look for.
        echo -n "Enter Name of employee your searching for : "
        read find

        # Print the header before the answer
	echo "Matching records for your search : "
        echo "Name -- Phone number -- ID"
        grep -i $find $BOOK
}

deletebook()
{
   BOOK="address-book.txt"
   echo " enter name "  
   read rn  
   grep ^$rn $BOOK
   if [ $? -ne 0 ]; then  
   echo "record for entered name does not exist "  
   else  
   grep -v $rn $BOOK>>tmp  
   cp tmp $BOOK  
   echo "deletion complete "  
   fi  
     
}

modifybook()
{
   BOOK="address-book.txt"
   echo " enter name "  
   read rn1  
   grep ^$rn $BOOK  
   if [ $? -ne 0 ]; then  
   echo "record for name does not exist "  
   else  
   echo " enter modified name "  
   read rn  
   echo " enter modified phone number  "  
   read nm  
   echo " enter modified id "  
   read sk  
  # echo " enter marks english "  
   #read eg  
   #echo " enter marks hindi "  
   #read hn  
   record="$rn -- $nm -- $sk  "  
   var=`grep -n ^$rn1 $BOOK | cut -c 1`  
   #echo $var  
   var1=`expr $var - 1`  
   head -$var1 $BOOK>temp  
   echo $record>>temp  
   var3=`wc -l < $BOOK`  
   var2=`expr $var3 - $var `  
   tail -$var2 $BOOK>>temp  
   cp temp $BOOK  
    fi  
}

 # Name of address book
        BOOK="address-book.txt"
	
        #exit=0
	answer="0"

        while [ $answer -ne 6 ]
        
	do
            echo "What operation do you want?"
            echo -e "1.add\n2.list\n3.find\n4.del\n5.Modify\n6.Exit: "
            read answer

	   case "$answer" in 
		#case 1 
		"1") createbook;;
	
		#case 2 
		"2") displaybook;;
	
		#case 3 
		"3") searchbook;;

		#case 4 
		"4") deletebook;;

		#case 5 
		"5") modifybook;;

		#case 6 
		"6") exit;;

		#default case
		*) echo "Please enter a valid choice!"
	   esac 
	

            #if [ "$answer" = "add" ]
            #then
                #./add.sh
		# createbook

            #elif [ "$answer" = "list" ]
            #then
		 #displaybook
                #./list.sh
            # elif [ "$answer" = "find" ]
             #then
		  # searchbook
                #./find.sh
             #elif [ "$answer" = "del" ]
             #then
		  #deletebook
                #./del.sh
             #elif [ "$answer" = "exit" ]
             #then
                # exit=1
             #else
                # echo "I do not understand the command."
             #fi
        done

        #exit 0
