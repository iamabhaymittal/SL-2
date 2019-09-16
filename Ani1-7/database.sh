i="y"
while [ $i = "y" ]
do
clear
echo -e " 1.View the Data Base \n 2.View Specific Records \n 3.Add Records \n 4.Delete Records \n 5.Modify Records \n 6.Exit \n Enter your choice \n"
read ch
    case $ch in
        1)cat student;;
        2)echo "Enter id "
          read s_id
          grep -w "$s_id" student;;
          if [ $? -ne 0 ]
          then
          	echo "Record not found"
          else
          	echo "Record found"		    
          fi
        3)echo "Enter new student id "
          read s_id
          echo "Enter new name:"
          read name
          echo "Enter designation "
          read des
          echo "Enter college name"
          read college
          echo "$s_id    $name    $des    $college">>student;;
        4)echo "Enter Id"
          read s_id
          grep -w "$s_id" student
          if [ $? -ne 0 ]
          then
          	echo "Record not found"	    
          fi
          grep -vw "$s_id" student >dbs1
          echo "Record is deleted"
          cat dbs1
          rm student
          mv dbs1 student;;
        5);;           
        6)exit;;
        *)echo "Invalid choice ";;
    esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done
