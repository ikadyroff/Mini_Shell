/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:45:19 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "minishell.h"
#include "parser_utils.h"

/**
 * Выделяет текущий маркер парсера и сбрасывает итератор cmd- in- и out-iterator.
 * int для указания успеха или неудачи
 */
int	init_curr_par_tok(void)
{
	t_par_tok	**par_toks;
	t_iter		*iter;

	par_toks = get_par_toks();
	iter = get_iter();
	if (par_toks[iter[par]] != NULL)
		return (EXIT_SUCCESS);
	iter[cmd] = 0;
	iter[in] = 0;
	iter[out] = 0;
	par_toks[iter[par]] = ft_calloc(1 + 1, sizeof(*par_toks[iter[par]]));
	if (par_toks[iter[par]] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	free_par_toks(t_par_tok *par_toks[], int exit_code)
{
	int	i;

	i = 0;
	while (par_toks[i])
	{
		ft_free_str_array(&par_toks[i]->cmd);
		ft_free_str_array(&par_toks[i]->in);
		ft_free_str_array(&par_toks[i]->out);
		free(par_toks[i]);
		i++;
	}
	free(par_toks);
	return (exit_code);
}

int	free_parser(t_par_tok *par_tok[], t_iter *iter, int exit_status)
{
	free_par_toks(par_tok, 0);
	free(iter);
	reset_iter();
	reset_par_toks();
	return (exit_status);
}

/**
 * Возвращает правильный размер для выделения массива Parser-Tokens-Array.
 * *lex_toks[]: 
 * Правильный размер для выделения
 */
size_t	get_tokens_size(char *lex_toks[])
{
	size_t	size;
	int		i;

	size = 0;
	i = 0;
	while (lex_toks[i])
	{
		if (ft_strlen(lex_toks[i]) == 2)
		{
			if (ft_strstr(lex_toks[i], "&&") \
			|| ft_strstr(lex_toks[i], "||") \
			|| ft_strstr(lex_toks[i], "<<"))
				size += 2;
		}
		if (ft_strlen(lex_toks[i]) == 1)
		{
			if (ft_strchr(lex_toks[i], '|') \
			|| ft_strchr(lex_toks[i], '(') \
			|| ft_strchr(lex_toks[i], ')'))
				size++;
		}
		i++;
	}
	size++;
	return (size);
}
