n=0
for i in file_tests/* 
do
	while read line || [ -n "$line" ]
	do
		((n+=1))
		valgrind --leak-check=full --log-file="log$n" ./minishell $line;
	done < "$i"
done
