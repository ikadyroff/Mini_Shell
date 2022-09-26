/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:40:22 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_UTILS_H
# define ENV_VAR_UTILS_H

/* ПЕРЕНОС ПЕРЕМЕННЫХ ENV_VARIABLES */
typedef struct s_env
{
	char	**envp;
	char	**env_var;
	char	*pwd;
	char	*oldpwd;
}			t_env;

// ENV VAR функции
t_env	*init_envv(char **envp);
void	free_envv(t_env *envv);
int		reinit_env_var(t_env *envv, char **argv);
char	*get_env_var_value(t_env *envv, char *var);
void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);

#endif