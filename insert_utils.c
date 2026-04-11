/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:03:16 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/11 18:06:43 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_to_a(t_stack **st1, t_stack **st2, t_count *count)
{
	int	pos;
	int	save;

	if (!(*st1) || (*st2)->rank < (*st1)->rank)
	{
		pa(st1, st2, count);
		return ;
	}
	pos = find_target(st1, (*st2)->rank);
	if (pos == -1)
	{
		pa(st1, st2, count);
		ra(st1, count);
		return ;
	}
	save = pos;
	while (pos-- > 0)
		ra(st1, count);
	pa(st1, st2, count);
	while (save-- > 0)
		rra(st1, count);
}
