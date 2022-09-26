/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:03:02 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_convert(unsigned long long dec, int uppcase, char *ptr)
{
	int	r;

	*(--ptr) = '\0';
	if (dec == 0)
		*(--ptr) = '0';
	while (dec != 0)
	{
		ptr--;
		r = dec % 16;
		if (r < 10)
			r += '0';
		else
		{
			if (uppcase == 0)
				r += 'W';
			else
				r += '7';
		}
		*ptr = r;
		dec /= 16;
	}
	return (ptr);
}

char	*ft_htoa(unsigned long long dec, int uppcase)
{
	char	*hexnum;
	char	*ptr;
	int		nbrlen;

	nbrlen = ft_hexnbrlen(dec);
	hexnum = malloc((nbrlen + 1) * sizeof(*hexnum));
	if (hexnum == NULL)
		return (NULL);
	ptr = hexnum + nbrlen + 1;
	return (ft_convert(dec, uppcase, ptr));
}
