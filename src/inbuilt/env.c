/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:12:05 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"

int	env(char **argv)
{
	int		i;
	t_env	*envv;

	envv = get_envv();
	if (envv == NULL || envv->env_var == NULL)
		return (EXIT_FAILURE);
	if (argv != NULL && argv[1] != NULL)
	{
		if (access(argv[1], F_OK) == 0)
		{
			ft_fprintf(STDERR_FILENO, "env: %s: Premission denied\n", argv[1]);
			return (126);
		}
		ft_fprintf(2, "env: %s: No such file or directory\n", argv[1]);
		return (127);
	}
	i = 0;
	while (envv->env_var && envv->env_var[i] != NULL)
	{
		if (ft_printf("%s\n", envv->env_var[i++]) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
