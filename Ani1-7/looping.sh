for a in 0 1 2 3 4 5 6 7 8 9
do
	if (( $a==5 ))
	then
		continue
	fi
	echo "Iteration no $a "	
done


a=0

while (( $a < 10 ))
do
	echo "$a"
	a=$((a+1))
done
