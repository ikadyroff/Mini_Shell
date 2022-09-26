/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_redir_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:11:19 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "minishell.h"
#include "parser_utils.h"

int	get_tok_redir_type(char *lex_tok)
{
	if (ft_strlen(lex_tok) == 1)
	{
		if (ft_strchr(lex_tok, '>'))
			return (is_out);
		if (ft_strchr(lex_tok, '<'))
			return (is_in);
		if (ft_strchr(lex_tok, '|'))
			return (is_pipe);
	}
	if (ft_strlen(lex_tok) == 2)
	{
		if (ft_strstr(lex_tok, ">>"))
			return (is_out_append);
		if (ft_strstr(lex_tok, "<<"))
			return (is_in_heredoc);
	}
	return (0);
}

bool	try_get_tok_redir_buf(char ****buf, size_t **buf_size, \
t_iter **buf_iter)
{
	if ((ft_strchr(get_curr_lex_tok(), '>') \
	&& ft_strlen(get_curr_lex_tok()) == 1) \
	|| (ft_strstr(get_curr_lex_tok(), ">>") \
	&& ft_strlen(get_curr_lex_tok()) == 2))
	{
		*buf = &get_curr_par_tok()->out;
		*buf_size = &get_curr_par_tok()->out_size;
		*buf_iter = &get_iter()[out];
		return (true);
	}
	else if ((ft_strchr(get_curr_lex_tok(), '<') \
	&& ft_strlen(get_curr_lex_tok()) == 1) \
	|| (ft_strstr(get_curr_lex_tok(), "<<") \
	&& ft_strlen(get_curr_lex_tok()) == 2))
	{
		*buf = &get_curr_par_tok()->in;
		*buf_size = &get_curr_par_tok()->in_size;
		*buf_iter = &get_iter()[in];
		return (true);
	}
	return (false);
}
