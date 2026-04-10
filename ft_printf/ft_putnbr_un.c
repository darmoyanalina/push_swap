/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:08:44 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 13:42:25 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_un(n / 10);
	c = n % 10 + '0';
	write(2, &c, 1);
	count++;
	return (count);
}
