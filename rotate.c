/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:21:13 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/09 15:09:48 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **st)
{
	t_stack	*first;
	t_stack	*last;

	if (!st || !(*st) || !(*st)->next)
		return ;
	first = *st;
	last = ft_lstlast(*st);
	// if (last == first->next)
	// {
	// 	swap(st);
	// 	return ;
	// }
	*st = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack **a, t_count *count)
{
	rotate(a);
	count->ra++;
	count->overall++;
	write(1, "ra\n", 3);
}

void	rb(t_stack **b, t_count *count)
{
	rotate(b);
	count->rb++;
	count->overall++;
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, t_count *count)
{
	ra(a, count);
	rb(b, count);
	count->rr++;
	count->ra--;
	count->rb--;
	count->overall--;
	write(1, "rr\n", 3);
}
