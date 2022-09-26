/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:01:52 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*src_buf;
	char	*dst_buf;

	if (dst == NULL && src == NULL)
		return (NULL);
	src_buf = src;
	dst_buf = dst;
	while (n > 0)
	{
		*dst_buf = *src_buf;
		dst_buf++;
		src_buf++;
		n--;
	}
	return (dst);
}
