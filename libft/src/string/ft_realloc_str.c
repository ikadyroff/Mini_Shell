/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:03:52 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
this function is similar to realloc, but only for strings
++ instead of malloc this uses calloc
-- it will create a new adress and free the old one of str
if allocation of the new size fails str will be freed
str: adress of the string you want to realloc
size: number of elements you want to realloc
new: adress of the reallocated string
*/
char	*ft_realloc_str(char *str, int size)
{
	char	*new;
	int		i;

	if (str == NULL)
		return (NULL);
	new = ft_calloc(size + 1, sizeof(*new));
	if (new == NULL)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str && str[i] && size--)
	{
		new[i] = str[i];
		i++;
	}
	free(str);
	return (new);
}
