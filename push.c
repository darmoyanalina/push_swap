/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:12:29 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/03 16:37:21 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	push(t_stack **st1, t_stack **st2)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!st2 || !*st2)
		return ;
	tmp1 = *st1;
	tmp2 = *st2;
	if (*st1)
		tmp1->prev = *st2;
	*st1 = tmp2;
	if ((*st2)->next)
	{
		*st2 = (*st2)->next;
		(*st2)->prev = NULL;
		tmp2->next = tmp1;
	}
	else
	{
		tmp2->next = tmp1;
		*st2 = NULL;
	}
}

void	pa(t_stack	**a, t_stack **b, t_count *count)
{
	push(a, b);
	count->pa++;
	count->overall++;
	write(1, "pa\n", 3);
}

void	pb(t_stack	**a, t_stack **b, t_count *count)
{
	push(b, a);
	count->pb++;
	count->overall++;
	write(1, "pb\n", 3);
}

