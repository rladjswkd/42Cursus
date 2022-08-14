/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:27:11 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:27:12 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

typedef enum e_stage
{
	EAT,
	SLEEP
}	t_stage;
typedef enum e_state
{
	ALIVE,
	DEAD
}	t_state;
#endif
