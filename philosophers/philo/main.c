/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:58 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:59 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include "arguments.h"
#include "construct.h"
#include "core.h"
#include "destruct.h"

int	main(int argc, char **argv)
{
	pthread_t		*threads;

	if (!parse_arguments(argc, argv))
		return (EXIT_FAILURE);
	if (!init_mutex_all())
		free_all(0, 1);
	if (!manage_threads(&threads))
		free_all(threads, 1);
	free_all(threads, 0);
	return (0);
}
