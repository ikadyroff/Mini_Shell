/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_arr_realloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:04:40 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_arr_realloc(char *array[], size_t size)
{
	char	**reallocated;
	int		i;

	reallocated = ft_calloc(size + 1, sizeof(*reallocated));
	if (reallocated == NULL)
		return (NULL);
	i = 0;
	while (size-- && array && array[i])
	{
		reallocated[i] = ft_strdup(array[i]);
		i++;
	}
	ft_free_str_array(&array);
	return (reallocated);
}
