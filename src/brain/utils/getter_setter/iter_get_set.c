/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_get_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:10:12 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.h"
#include "parser_utils.h"

static t_iter	*_get_iter(t_iter *iter, bool reset)
{
	static t_iter	*static_iter = NULL;

	if (iter == NULL && !reset)
		return (static_iter);
	if (reset)
	{
		static_iter = NULL;
		return (NULL);
	}
	static_iter = iter;
	return (static_iter);
}

t_iter	*get_iter(void)
{
	return (_get_iter(NULL, false));
}

void	set_iter(t_iter *iter)
{
	_get_iter(iter, false);
}

void	reset_iter(void)
{
	_get_iter(NULL, true);
}
