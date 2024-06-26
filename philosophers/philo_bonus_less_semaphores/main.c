/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:06 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:08 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#include <semaphore.h>
#include <stdlib.h>
#include "arguments.h"
#include "constants.h"
#include "construct.h"
#include "core.h"
#include "shared.h"
#include "handle.h"

static void	unlink_sem_all(void)
{
	sem_unlink(FORK_NAME);
	sem_unlink(RIGHTS_NAME);
	sem_unlink(LAST_EAT_NAME);
	sem_unlink(N_EAT_NAME);
	sem_unlink(FLAG_NAME);
}

int	main(int argc, char **argv)
{
	unlink_sem_all();
	if (!parse_arguments(argc, argv))
		return (1);
	if (!init_sem_all())
		return (close_sem_all() + 1);
	manage_subprocess();
	return (close_sem_all());
}
