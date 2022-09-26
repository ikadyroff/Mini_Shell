/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:05:12 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static size_t	ft_jmpend(char	**s, size_t n)
{
	while (n && **s)
	{
		(*s)++;
		n--;
	}
	return (n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dsiz)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dst_len;

	d = dst;
	s = src;
	n = dsiz;
	n = ft_jmpend(&d, n);
	dst_len = d - dst;
	if (!n)
		return (dst_len + ft_strlen(s));
	while (*s)
	{
		if (n > 1)
		{
			*d = *s;
			d++;
			n--;
		}
		s++;
	}
	*d = 0;
	return (dst_len + (s - src));
}
