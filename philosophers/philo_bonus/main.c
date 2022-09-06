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
#include "monitor_semaphore.h"
#include "handle.h"
#include "destruct.h"

int	main(int argc, char **argv)
{
	sem_unlink(FORK_NAME);
	sem_unlink(RIGHTS_NAME);
	sem_unlink(LAST_EAT_NAME);
	sem_unlink(N_EAT_NAME);
	sem_unlink(DIED_NAME);
	if (!parse_arguments(argc, argv))
		return (0);
	if (!init_sem_all())
		return (destruct_all());
	manage_subprocess();
	destruct_all();
	return (0);
}
