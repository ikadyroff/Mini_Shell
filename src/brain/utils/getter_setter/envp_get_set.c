/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_get_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:10:03 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**_get_envp(char *envp[], bool reset)
{
	static char	**static_envp = NULL;

	if (envp == NULL && !reset)
		return (static_envp);
	if (reset)
	{
		static_envp = NULL;
		return (NULL);
	}
	static_envp = envp;
	return (static_envp);
}

void	set_envp(char *envp[])
{
	_get_envp(envp, false);
}

char	**get_envp(void)
{
	return (_get_envp(NULL, false));
}

void	reset_envp(void)
{
	_get_envp(NULL, true);
}
