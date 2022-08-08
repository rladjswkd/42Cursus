int	malloc_wrapper(size_t size, void **ptr)
{
	size_t	 i;
	char	*cptr;

	*ptr = malloc(size);
	if (!(*ptr))
		return (0);
	i = 0;
	cptr = (char *)(*ptr);
	while (i < size)
		cptr[i++] = 0;
	return (1);
}