/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:06:11 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*substr;
	int		str_len;

	i = 0;
	str_len = ft_strlen(s);
	if (s == NULL || str_len == 0)
		return (NULL);
	if (start == (size_t)ft_strlen(s))
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	substr = malloc(sizeof(*substr) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (len-- && start < (unsigned int)str_len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
