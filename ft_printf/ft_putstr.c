/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:03:30 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 13:42:47 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	size;

	if (!s)
		return (write(2, "(null)", 6));
	size = ft_strlen(s);
	return (write(2, s, size));
}
