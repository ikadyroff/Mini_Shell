/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:01:57 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	const char	*src_buf;
	char		*dst_buf;

	if (dst > src)
	{
		src_buf = src + n - 1;
		dst_buf = dst + n - 1;
	}
	else
		return (ft_memcpy(dst, (void *)src, n));
	while (n > 0)
	{
		*dst_buf = *src_buf;
		dst_buf--;
		src_buf--;
		n--;
	}
	return (dst);
}
