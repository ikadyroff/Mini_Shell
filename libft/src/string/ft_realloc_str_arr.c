/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:03:47 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
this function is similar to realloc, but only for string-arrays
++ instead of malloc this uses calloc
-- it will create a new adress and free the old one of arr
if allocation of the new size fails arr will be freed
arr: adress of the array you want to realloc
size: number of elements you want to realloc
new: adress of the reallocated array of strings
*/
char	**ft_realloc_str_arr(char **arr, int size)
{
	char	**new;
	int		i;

	if (arr == NULL)
		return (NULL);
	new = ft_calloc(size + 1, sizeof(char *));
	if (new == NULL)
	{
		ft_free_str_array(&arr);
		return (NULL);
	}
	i = 0;
	while (size-- && arr && arr[i])
	{
		new[i] = ft_strdup(arr[i]);
		i++;
	}
	ft_free_str_array(&arr);
	return (new);
}
