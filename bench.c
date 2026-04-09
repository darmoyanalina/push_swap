/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:11:25 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/09 12:11:25 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bench(t_count *count, int disorder)
{
	printf("[bench] disorder: %d.%d%%\n", disorder * 100, (disorder * 10000) % 100);
	printf("[bench] strategy: \n");
	printf("[bench] total_ops: %d\n", count->overall);
	printf("[bench] sa: %d sb: %d ss: %d ", count->sa, count->sb, count->ss);
	printf("pa: %d pb: %d\n", count->pa, count->pb);
	printf("[bench] ra: %d rb: %d rr: %d ", count->ra, count->rb, count->rr);
	printf("rra: %d rrb: %d rrr: %d\n", count->rra, count->rrb, count->rrr);
}
