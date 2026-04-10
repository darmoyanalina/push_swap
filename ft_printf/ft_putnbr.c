/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:02:56 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 13:42:54 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
