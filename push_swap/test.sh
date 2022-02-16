make all
if [ "$#" -eq 1 ]
then
	ARG=`seq -5000 5000 | sort -R | head -$1 | tr "\n" " "`
else
	ARG="$@"
fi
echo $ARG
./push_swap $ARG > result
cat result | wc -l
./checker $ARG < result
make fclean >> result
rm -rf result
