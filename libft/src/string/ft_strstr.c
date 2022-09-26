/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:05:59 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *to_find)
{
	int	i;

	if (ft_strlen(to_find) == 0)
		return ((char *)s);
	i = 0;
	while (s && *s)
	{
		if (*s == *to_find)
		{
			i = 0;
			while (s[i] == to_find[i] && s[i])
				i++;
			if (i == ft_strlen(to_find))
				return ((char *)s);
		}
		s++;
	}
	return (0);
}
