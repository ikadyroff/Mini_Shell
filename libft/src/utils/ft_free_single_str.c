/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_single_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:06:26 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
will free a single string out of a given array
will move the following strings to fill the gap
will reallocate the array to the correct size
*/
void	ft_free_single_str(char ***arr, int i)
{
	if (*arr != NULL)
		ft_free_str(&(*arr)[i++]);
	while (*arr != NULL && (*arr)[i] != NULL)
	{
		(*arr)[i - 1] = (*arr)[i];
		i++;
	}
	(*arr)[--i] = NULL;
	if (*arr != NULL && (*arr)[i] == NULL)
		*arr = ft_realloc_str_arr(*arr, i + 1);
}
