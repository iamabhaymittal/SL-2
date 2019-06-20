
#If 
a=10 
b=20 
if [ $a == $b ]
then
	echo "a is equal to b"
fi

if [ $a != $b ]
then
	echo "a is not equal to b"
fi



#Switch

CARS="bmw"

case "$CARS" in
	"saacs") echo "sfaf" ;;
	"bmw") echo "1111afsaf" ;;
	"sadsa") echo "afsasf" ;;
	"bmw") echo "asfsafsa" ;;
esac



#For

for a in 1 2 3 4 5 6 7 8 9 10
do
	if [ $a == 5 ]
	then
		break
	fi
	echo "Interation no $a"
done 


a=0

#While

while [ $a -lt 10 ]
do
	echo $a
	a=`expr $a + 1`

done
