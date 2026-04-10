/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:11:25 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 14:13:36 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*strategy(t_alg *c_algs)
{
	if (c_algs->adaptive < 0 && c_algs->algorithm == 1)
		return ("Simple / O(n²)");
	else if (c_algs->adaptive < 0 && c_algs->algorithm == 2)
		return ("Medium / O(n√n)");
	else if (c_algs->adaptive < 0 && c_algs->algorithm == 3)
		return ("Complex / O(nlogn)");
	else if (c_algs->adaptive > 0 && c_algs->algorithm == 1)
		return ("Adaptive / O(n²)");
	else if (c_algs->adaptive > 0 && c_algs->algorithm == 2)
		return ("Adaptive / O(n√n)");
	else
		return ("Adaptive / O(nlogn)");
}

void	bench(t_count *count, float disorder, t_alg *c_algs)
{
	const char	*strategy_c;

	strategy_c = strategy(c_algs);
	ft_printf("[bench] disorder: %d.%d%%\n", (int)(disorder * 100), (int)((int)(disorder * 10000) % 100));
	ft_printf("[bench] strategy: %s\n", strategy_c);
	ft_printf("[bench] total_ops: %d\n", count->overall);
	ft_printf("[bench] sa: %d sb: %d ss: %d ", count->sa, count->sb, count->ss);
	ft_printf("pa: %d pb: %d\n", count->pa, count->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d ", count->ra, count->rb, count->rr);
	ft_printf("rra: %d rrb: %d rrr: %d\n", count->rra, count->rrb, count->rrr);
}
