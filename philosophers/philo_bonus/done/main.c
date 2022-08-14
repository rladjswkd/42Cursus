int	main(int argc, char **argv)
{
	// access_program_flag_sem에 대해 sem_wait을 main process의 monitor를 생성하기 전에 수행해야 한다.
	if (!parse_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_sem_all())
		free_all(1);
	if (!manage_subprocess())
		free_all(1);
	free_all(0);
	return (0);
}
