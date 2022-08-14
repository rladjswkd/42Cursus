/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 23:26:57 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 23:26:58 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

int		is_flag_set(void);
void	set_flag(void);
int		get_last_eat(int idx);
void	print_state(int idx, char *str, int state);
#endif
