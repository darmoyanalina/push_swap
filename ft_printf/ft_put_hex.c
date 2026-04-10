/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:48:11 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 13:42:14 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int n, char k)
{
	char	c;
	int		count;
	char	*lower;
	char	*upper;

	count = 0;
	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (n > 15)
		count += ft_put_hex(n / 16, k);
	if (k == 'x')
		c = lower[n % 16];
	if (k == 'X')
		c = upper[n % 16];
	write(2, &c, 1);
	count++;
	return (count);
}
