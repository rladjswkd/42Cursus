/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:02:32 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/21 16:02:33 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "shared.h"
#include "constants.h"
#include "monitor_semaphore.h"
#include "handle.h"

int	destruct_all(void)
{
	int	n;

	n = access_args(GET).n_philo;
	close_sem_all();
	while (n--)
	{
		free(access_flag_names(GET)[n]);
		free(access_finish_names(GET)[n]);
	}
	free(access_flag_names(GET));
	free(access_finish_names(GET));
	free(access_flag_addr(GET));
	free(access_finish_addr(GET));
	return (0);
}
