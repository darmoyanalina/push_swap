/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:19:47 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 14:18:21 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *c, va_list args)
{
	int	count;

	count = 0;
	if (*c == 'd' || *c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (*c == 'u')
		count += ft_putnbr_un(va_arg(args, unsigned int));
	if (*c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (*c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (*c == 'x' || *c == 'X')
		count += ft_put_hex(va_arg(args, unsigned int), *c);
	if (*c == 'p')
		count += ft_put_address(va_arg(args, void *));
	if (*c == '%')
		count += write(2, "%", 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printed;
	va_list	args;

	va_start(args, str);
	i = 0;
	printed = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
			printed += ft_putchar(str[i++]);
		if (str[i] == '%')
		{
			i++;
			printed += check_format(&str[i++], args);
		}
	}
	va_end(args);
	return (printed);
}
