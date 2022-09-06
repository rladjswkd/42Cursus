/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:19:04 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/15 17:19:05 by gyepark          ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H

void	synchronize_start_time(void);
void	print_state(int idx, char *str, int state);
int		close_sem_all(void);
#endif
