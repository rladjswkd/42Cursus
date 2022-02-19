/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:10:31 by gyepark           #+#    #+#             */
/*   Updated: 2022/02/19 11:00:01 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nl(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}

static int	read_stdin(char **builder)
{
	char	buffer[BUFFER_SIZE + 1];
	int		count;
	char	*temp;

	while (find_nl(*builder) < 0)
	{
		count = read(0, buffer, BUFFER_SIZE);
		if (count < 1)
			return (count);
		buffer[count] = '\0';
		temp = ft_strjoin(*builder, buffer);
		if (!temp)
			return (-1);
		free(*builder);
		*builder = temp;
	}
	return (1);
}

static char	*build_line(char **builder)
{
	char	*ret;
	char	*temp;
	int		nl_idx;
	int		len;

	nl_idx = find_nl(*builder);
	len = ft_strlen(*builder);
	if (nl_idx == -1)
	{
		if (!len)
			return (0);
		return (*builder);
	}
	ret = ft_substr(*builder, 0, nl_idx);
	if (!ret)
		return (0);
	temp = ft_substr(*builder, nl_idx + 1, len - nl_idx - 1);
	if (!temp)
		return (0);
	free(*builder);
	*builder = temp;
	return (ret);
}

static int	is_valid_instruction(char *str)
{
	return (are_same_strings(str, "sa")
			|| are_same_strings(str, "sb")
			|| are_same_strings(str, "ss")
			|| are_same_strings(str, "pa")
			|| are_same_strings(str, "pb")
			|| are_same_strings(str, "ra")
			|| are_same_strings(str, "rb")
			|| are_same_strings(str, "rr")
			|| are_same_strings(str, "rra")
			|| are_same_strings(str, "rrb")
			|| are_same_strings(str, "rrr")
	       );
}

char	*get_next_line(void)
{
	static char	*builder = 0;
	char		*output;

	if (!builder)
	{
		builder = (char *)malloc(sizeof(char));
		if (!builder)
			return (0);
		builder[0] = '\0';
	}
	if (read_stdin(&builder) == -1)
	{
		free(builder);
		return (0);
	}
	output = build_line(&builder);
	if (!output)
	{
		free(builder);
		return (0);
	}
	if (output != builder && !is_valid_instruction(output))
		free(builder);
	return (output);
}
