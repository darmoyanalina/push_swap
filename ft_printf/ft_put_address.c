/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:08:05 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 13:42:08 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_ad(uintptr_t n)
{
	char	c;
	int		count;
	char	*lower;

	count = 0;
	lower = "0123456789abcdef";
	if (n > 15)
		count += ft_puthex_ad(n / 16);
	c = lower[n % 16];
	write(2, &c, 1);
	count++;
	return (count);
}

int	ft_put_address(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(2, "(nil)", 5));
	count += write(2, "0x", 2);
	count += ft_puthex_ad((uintptr_t)ptr);
	return (count);
}
