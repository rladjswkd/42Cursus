/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:53:25 by gyepark           #+#    #+#             */
/*   Updated: 2022/08/10 12:53:26 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include "constants.h"
# include "token.h"
# include "extractor.h"
# include "syntax.h"

int	lexer(char *input, t_list *token_header);
#endif
