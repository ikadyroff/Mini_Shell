/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehoundey <ehoundey@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:57:16 by ehoundey          #+#    #+#             */
/*   Updated: 2022/06/20 17:59:21 by ehoundey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_handle(char c, va_list args)
{
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (c == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_putlhex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_putuhex(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	va_start(args, format);
	printed_chars = 0;
	while (*format)
	{
		if (*format == '%')
		{
			printed_chars += ft_handle(*(++format), args);
			if (!(*format))
				break ;
		}
		else
			printed_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}
