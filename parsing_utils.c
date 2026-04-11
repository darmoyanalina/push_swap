/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:10:07 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/11 14:10:50 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(t_alg *c_algs, t_count *count)
{
	write (2, "Error\n", 6);
	free_algs(c_algs, count);
	exit(1);
}

int	ft_isval(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}
