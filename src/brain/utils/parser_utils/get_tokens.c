/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:30:03 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "brain.h"
#include "parser_utils.h"

/**
 * Пытается получить команду из текущего лексерного маркера 
 * *lex_tok: Текущий лексерный токен
 * *par_tok: Парсерный токен для записи команды
 * *iter: Итератор парсера, лексера, cmd, in, out
 * int для указания успеха или неудачи
 */
int	get_tok_cmd(char *lex_tok, t_par_tok *par_tok, t_iter *iter)
{
	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (!is_quote_token(lex_tok) && (is_special_token(lex_tok) \
	|| is_redir_token(lex_tok) || (ft_strchr(lex_tok, '(') \
	|| ft_strchr(lex_tok, ')'))))
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	par_tok->cmd_size++;
	par_tok->cmd = ft_str_arr_realloc(par_tok->cmd, par_tok->cmd_size);
	if (par_tok->cmd == NULL)
		return (EXIT_FAILURE);
	par_tok->cmd[iter[cmd]] = ft_strdup(lex_tok);
	if (par_tok->cmd[iter[cmd]] == NULL)
		return (EXIT_FAILURE);
	iter[lex]++;
	iter[cmd]++;
	return (EXIT_SUCCESS);
}

/**
 * Пытается получить перенаправления out и in из текущего лексерного маркера
 * *lex_toks[]: Лексические лексемы
 * *iter: Итератор парсера, лексера, cmd, in, out
 * int для указания успеха или неудачи
 */
int	get_tok_redir(char *lex_toks[], t_iter *iter)
{
	int		i;
	t_iter	*buf_iter;
	char	***buf;
	size_t	*buf_size;

	if (lex_toks[iter[lex]] == NULL)
		return (EXIT_SUCCESS);
	if (!try_get_tok_redir_buf(&buf, &buf_size, &buf_iter))
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	get_curr_par_tok()->redir_type \
	[get_tok_redir_type(lex_toks[iter[lex]])] = true;
	(*buf_size) += 2;
	*buf = ft_str_arr_realloc(*buf, *buf_size);
	if (*buf == NULL)
		return (EXIT_FAILURE);
	i = 2;
	while (i--)
	{
		(*buf)[*buf_iter] = ft_strdup(lex_toks[iter[lex]++]);
		if ((*buf)[(*buf_iter)++] == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * Пытается получить специальный разделительный токен из текущего токена лексера.
 * Создает новый маркер синтаксического анализатора, если необходимо.
 * Токены специальных разделителей включают: and, or, subshell.
 * *lex_toks[]: лексерные лексемы
 * *par_toks[]: Токены синтаксического анализатора
 * *iter: Итератор парсера, лексера, команды, in, out.
 * int для указания успеха, неудачи или прерывания
 */
int	get_special_tok(char *lex_tok, t_par_tok *par_toks[], t_iter *iter)
{
	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (ft_strchr(lex_tok, '\'') || ft_strchr(lex_tok, '\"'))
		return (EXIT_SUCCESS);
	if ((ft_strstr(lex_tok, "&&") || ft_strstr(lex_tok, "||")) \
	&& ft_strlen(lex_tok) == 2)
	{
		iter[par]++;
		if (init_curr_par_tok() == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (ft_strstr(lex_tok, "&&"))
			par_toks[iter[par]++]->type = and;
		else if (ft_strstr(lex_tok, "||"))
			par_toks[iter[par]++]->type = or;
		iter[lex]++;
		return (EXIT_BREAK);
	}
	if (ft_strchr(lex_tok, '('))
		return (get_subshell_tok(iter));
	return (EXIT_SUCCESS);
}

/**
 * Пытается получить тип токена из текущего лексерного токена.
 * Типы токенов включают: pipe, in- out- append-redirections и
 * * heredoc
 * * *lex_tok: Текущий лексерный токен
 * *iter: Итератор парсера, лексера, команды, in, out.
 * int для указания неудачи или успеха
 */
int	get_tok_type(char *lex_tok, t_iter *iter)
{
	t_par_tok	*par_tok;

	if (lex_tok == NULL)
		return (EXIT_SUCCESS);
	if (init_curr_par_tok() == EXIT_FAILURE)
		return (EXIT_FAILURE);
	par_tok = get_curr_par_tok();
	if (ft_strlen(lex_tok) == 1)
	{
		if (ft_strchr(lex_tok, '|'))
			return (set_tok_type_pipe(par_tok, iter));
		if (ft_strchr(lex_tok, '<'))
			par_tok->redir_type[is_in] = true;
		if (ft_strchr(lex_tok, '>'))
			par_tok->redir_type[is_out] = true;
	}
	if (ft_strlen(lex_tok) == 2 && ft_strstr(lex_tok, "<<"))
		par_tok->redir_type[is_in_heredoc] = true;
	if (ft_strlen(lex_tok) == 2 && ft_strstr(lex_tok, ">>"))
		par_tok->redir_type[is_out_append] = true;
	if ((lex_tok[0] != '\'' && lex_tok[0] != '\"') \
	&& (ft_strchr(lex_tok, '(') && ft_strchr(lex_tok, ')')))
		par_tok->type = subshell;
	return (EXIT_SUCCESS);
}
