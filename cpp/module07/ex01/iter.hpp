template <class T, class U, class V>
void	iter(T *array, U len, V (*fp)(T &)){
	for (U i = 0; i < len; i++)
		(*fp)(array[i]);	
}