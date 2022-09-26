/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:05:08 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
will append s2 to s1
will not free s1 afterwards
*/
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;
	int		joined_len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	joined_len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc((joined_len + 1) * sizeof(*joined));
	if (joined == NULL)
		return (NULL);
	while (s1 && *s1)
		*joined++ = *s1++;
	while (s2 && *s2)
		*joined++ = *s2++;
	*joined = '\0';
	return (joined - joined_len);
}
