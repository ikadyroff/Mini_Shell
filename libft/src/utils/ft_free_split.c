/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:06:30 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Frees allocated array returned by ft_split function.
 * Assumes that ft_split successfully split the string.
 * Returns NULL
*/
void	*ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		ft_free_str(&split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
