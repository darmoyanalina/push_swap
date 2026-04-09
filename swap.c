/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:23:15 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/08 21:05:07 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack **st)
{
	t_stack	*first;
	t_stack	*second;

	if (!st || !*st || !(*st)->next)
		return ;
	first = *st;
	second = first->next;
	*st = second;
	second->prev = NULL;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
}

void	sa(t_stack	**a, t_count *count)
{
	swap(a);
	count->sa++;
	count->overall++;
	write(1, "sa\n", 3);
}

void	sb(t_stack **b, t_count *count)
{
	swap(b);
	count->sb++;
	count->overall++;
	write(1, "sb\n", 3);
}

void	ss(t_stack	**a, t_stack	**b, t_count *count)
{
	sa(a, count);
	sb(b, count);
	count->ss++;
	count->sa--;
	count->sb--;
	count->overall--;
	write(1, "ss\n", 3);
}
