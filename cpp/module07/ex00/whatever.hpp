template <class T>
void	swap(T &val1, T &val2){
	T	temp = val1;
	val1 = val2;
	val2 = temp;
}

template <class T>
T	min(T val1, T val2){
	T	res = val2;
	if (val1 < val2)
		res = val1;
	return (res);
}

template <class T>
T	max(T val1, T val2){
	T	res = val2;
	if (val1 > val2)
		res = val1;
	return (res);	
}