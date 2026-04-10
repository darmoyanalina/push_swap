/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:43 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/09 15:09:57 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stack **st)
{
	t_stack	*first;
	t_stack	*last;

	if (!st || !(*st) || !(*st)->next)
		return ;
	first = *st;
	last = ft_lstlast(*st);
	// if (last->prev == first)
	// {
	// 	swap(st);
	// 	return ;
	// }
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*st = last;
}

void	rra(t_stack **a, t_count *count)
{
	r_rotate(a);
	count->rra++;
	count->overall++;
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b, t_count *count)
{
	r_rotate(b);
	count->rrb++;
	count->overall++;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, t_count *count)
{
	rra(a, count);
	rrb(b, count);
	count->rrr++;
	count->rra--;
	count->rrb--;
	count->overall--;
	write(1, "rrr\n", 4);
}

