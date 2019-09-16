a=30
b=20

if (( $a == $b )) 
then 
    echo "a is equal to b"
else
    echo "a is not equal to b"
fi 



if (( $a < $b ))
then
	echo "A is smaller than B"
elif (( $a > $b ))
then
	echo "A is greater than B"
else
	echo "A and B are equal"	
fi



CARS="3"

case "$CARS" in  
	"1") echo "Headquarters - Affalterbach, Germany" ;; 
	
	"2") echo "Headquarters - Ingolstadt, Germany" ;; 
	 
	"3") echo "Headquarters - Chennai, Tamil Nadu, India" ;; 
esac 
		
