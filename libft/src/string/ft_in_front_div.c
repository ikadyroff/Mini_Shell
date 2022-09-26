/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_front_div.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:03:09 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
this will add src infront of dst divided by div
dst will be free'd
returns NULL if dst == NULL or src == NULL or if error
*/
char	*ft_in_front_div(char **dst, char *src, char *div)
{
	char	*out;

	out = ft_strdup(src);
	if (out == NULL)
		return (NULL);
	out = ft_append(&out, div);
	if (out == NULL)
		return (NULL);
	out = ft_append(&out, *dst);
	if (out == NULL)
		return (NULL);
	ft_free_str(dst);
	return (out);
}
