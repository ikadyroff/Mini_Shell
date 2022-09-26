/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 18:06:53 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  will perror with the given message *msg and return exit_status
 * @note
 * @param  exit_status: the exit status you want ft_perror to give
 * @param  *msg: the message that should be printet by perror before the error
 * @retval exit_status
 */
int	ft_perror(int exit_status, char *msg)
{
	perror(msg);
	return (exit_status);
}
