/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inbuilt_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:41:24 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INBUILT_UTILS_H
# define INBUILT_UTILS_H

# include "env_var_utils.h"

/* ТРАНСПОРТИРОВКА ПЕРЕМЕННЫХ EXPORT */
typedef struct s_export
{
	int		i;
	int		j;
	char	*var;
}			t_export;

int		export_only(t_env *envv);
int		export_input_error(char **argv);
int		export_special(t_env *envv, t_export *exp);
int		export_wd(t_env *envv, t_export *exp, char **argv);

#endif