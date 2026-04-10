/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:47:51 by adarmoya          #+#    #+#             */
/*   Updated: 2026/02/23 16:47:51 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	n_length(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	handle_negative(long long *n, char *s)
{
	if (*n < 0)
	{
		s[0] = '-';
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	int			size;
	int			i;
	long long	k;
	char		*s;

	k = (long long)n;
	size = n_length(n);
	s = malloc(size + 1);
	if (!s)
		return (NULL);
	i = size - 1;
	if (n == 0)
		s[0] = '0';
	handle_negative(&k, s);
	while (k)
	{
		s[i--] = '0' + (k % 10);
		k /= 10;
	}
	s[size] = '\0';
	return (s);
}
