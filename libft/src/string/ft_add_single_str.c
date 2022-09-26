/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_single_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:02:26 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
add new after (*arr)[pos]
*/
char	**ft_add_single_str(char ***arr, int pos, char *new)
{
	int		i;

	pos++;
	if (new == NULL)
	{
		ft_free_str_array(arr);
		return (NULL);
	}
	*arr = ft_realloc_str_arr(*arr, ft_str_arr_len(*arr) + 1);
	if (*arr == NULL)
		return (NULL);
	i = ft_str_arr_len(*arr);
	while (i > pos)
	{
		(*arr)[i] = (*arr)[i - 1];
		i--;
	}
	(*arr)[i] = ft_strdup(new);
	if ((*arr)[i] == NULL)
	{
		ft_free_str_array(arr);
		return (NULL);
	}
	return (*arr);
}
