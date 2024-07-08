echo "Enter two numbers:"
read a
read b

if [ $a -gt $b ];
then
	echo "$a is largest"
else
	echo "$b is largest"
fi
