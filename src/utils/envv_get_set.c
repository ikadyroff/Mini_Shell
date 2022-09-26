/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envv_get_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:12:38 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

static t_env	*_get_envv(t_env *envv)
{
	static t_env	*static_envv = NULL;

	if (envv == NULL)
		return (static_envv);
	static_envv = envv;
	return (static_envv);
}

void	set_envv(t_env *envv)
{
	_get_envv(envv);
}

t_env	*get_envv(void)
{
	return (_get_envv(NULL));
}

char	**get_env_var(void)
{
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL)
		return (NULL);
	return (envv->env_var);
}
