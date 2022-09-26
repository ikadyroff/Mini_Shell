/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:03:44 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_assigndigits(char *snbr, long lnbr, int i)
{
	int	nbr;
	int	r;

	r = 0;
	nbr = lnbr;
	snbr += i;
	*snbr = '\0';
	if (nbr == 0)
		*(--snbr) = '0';
	while (lnbr != 0)
	{
		snbr--;
		r = lnbr % 10;
		if (r < 0)
			r *= -1;
		*snbr = r + '0';
		lnbr /= 10;
	}
	if (nbr < 0)
		*(--snbr) = '-';
	return (snbr);
}

char	*ft_itoa(int nbr)
{
	char	*snbr;
	long	lnbr;
	int		i;

	lnbr = nbr;
	i = ft_nbrlen(lnbr);
	if (nbr < 0)
		i++;
	snbr = malloc(sizeof(*snbr) * (i + 1));
	if (snbr == NULL)
		return (NULL);
	snbr = ft_assigndigits(snbr, lnbr, i);
	return (snbr);
}
