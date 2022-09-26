/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:05:25 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*iterated;
	int		i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	iterated = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (iterated == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		iterated[i] = f(i, s[i]);
		i++;
	}
	iterated[i] = 0;
	return (iterated);
}
