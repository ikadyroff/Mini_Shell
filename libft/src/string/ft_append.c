/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:02:37 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends src to dst, frees dst and returns newly created string */
char	*ft_append(char **dst, char *src)
{
	char	*dst_buf;
	char	*appendet;
	int		appendet_len;

	if (dst == NULL)
		dst_buf = NULL;
	else
		dst_buf = *dst;
	appendet_len = ft_strlen(dst_buf) + ft_strlen(src);
	if (appendet_len == 0)
	{
		ft_free((void *)dst);
		return (NULL);
	}
	appendet = malloc((appendet_len + 1) * sizeof(*appendet));
	if (appendet == NULL)
		return (NULL);
	while (dst_buf && *dst_buf)
		*appendet++ = *dst_buf++;
	while (src && *src)
		*appendet++ = *src++;
	*appendet = '\0';
	ft_free((void *)dst);
	return (appendet - appendet_len);
}
