RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
NC='\033[0m'

while [ 1 -lt 2 ] 
do
	clear
	echo
	echo
	echo -e "${YELLOW}=========================="
	echo -e "${BLUE}        M E N U${NC}"
	echo "=========================="
	echo  "1. Create address book"
	echo  "2. View address book"
	echo  "3. Insert a record"
	echo  "4. Delete a record"
	echo  "3. Modify a record"
	
	echo  "0. Exit"
	echo "=========================="

	echo -n "Enter your choice:"

	read ch
	case $ch in 
		1) 
			echo "1" ;;
		2) 
			echo "2" ;;
		3) 
			echo "3" ;;
		0)
			echo -e "${RED}Thank You!${NC}"
			break ;;
	esac
	
done

