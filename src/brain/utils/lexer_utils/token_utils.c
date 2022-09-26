/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:10:51 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer_utils.h"

bool	is_special_char(char curr, char next)
{
	if (curr == '|')
		return (true);
	if (curr == '>')
		return (true);
	if (curr == '<')
		return (true);
	if (curr == ';')
		return (true);
	if (curr == '&' && next && next == '&')
		return (true);
	return (false);
}

size_t	get_next_token_size(char *token, char next_special)
{
	size_t	size;

	size = 0;
	if (*token == next_special)
	{
		while (*token && *token == next_special)
		{
			token++;
			size++;
		}
	}
	else
	{
		while (*token && *token != next_special)
		{
			size++;
			token++;
		}
	}
	return (size);
}

char	get_next_special(char *token)
{
	while (*token)
	{
		if (*token == '|' || *token == '<' \
			|| *token == '>' || *token == ';')
			return (*token);
		if (*token == '&' && *(token + 1) && *(token + 1) == '&')
			return (*token);
		token++;
	}
	return ('\0');
}

bool	token_is_unadjusted(char *token)
{
	if (ft_strchr(token, '\'') || ft_strchr(token, '\"'))
		return (false);
	if ((ft_strchr(token, '|') && !ft_strstr(token, "||")) \
	|| (ft_strchr(token, '<') && !ft_strstr(token, "<<")) \
	|| (ft_strchr(token, '>') && !ft_strstr(token, ">>")))
		if (ft_strlen(token) != 1)
			return (true);
	if (ft_strstr(token, "&&") || ft_strstr(token, "<<") \
	|| ft_strstr(token, ">>") || ft_strstr(token, "||"))
		if (ft_strlen(token) != 2)
			return (true);
	return (false);
}
