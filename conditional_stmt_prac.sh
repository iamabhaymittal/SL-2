#Initializing two variables 
a=10 
b=20 
  
#Check whether they are equal 
if [ $a == $b ]
then
	echo "a is equal to b"
fi

if [ $a != $b ]
then
	echo "a is not equal to b"
fi

CARS="bmw"

case "$CARS" in
	"saacs") echo "sfaf" ;;
	"bmw") echo "1111afsaf" ;;
	"sadsa") echo "afsasf" ;;
	"bmw") echo "asfsafsa" ;;
esac
