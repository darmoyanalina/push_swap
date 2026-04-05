/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:37:39 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/05 20:51:11 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pivot_val(t_stack *st)
{
	int		middle;
	int		i;
	t_stack	*piv;

	middle = ft_lstsize(st)/2;
	piv = st;
	i = 0;
	while (i < middle)
	{
		piv = piv->next;
		i++;
	}
	return (piv->rank);
}

void	q_sort_helper_b(t_stack **a, t_stack **b, int pivot)
{
	int	b_top;

	if (!(*b))
		return ;
	b_top = (*b)->content;
	if (b_top <= pivot)
		pa(a, b);
	else
		rb(b);
	while (*b && b_top != (*b)->content)
	{
		if (*a && b_top == (*a)->content)
			b_top = ((*b)->content);
		if ((*b)->content <= pivot)
			pa(a, b);
		else
			rb(b);
	}
}

void	q_sort_helper_a(t_stack **a, t_stack **b, int pivot)
{
	int	a_top;

	if (!(*a) || !disorder(*a))
		return ;
	a_top = (*a)->rank;
	if (a_top < pivot)
		pb(a, b);
	else
		ra(a);
	while (*a && a_top != (*a)->rank)
	{
		if (*b && a_top == (*b)->rank)
			a_top = ((*a)->rank);
		if ((*a)->rank < pivot)
			pb(a, b);
		else
			ra(a);
	}
	while (pivot != (*a)->rank)
		ra(a);
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int		pivot;

	if (!disorder(*a) || !(*a)->next)
		return ;
	pivot = pivot_val(*a);
	q_sort_helper_a(a, b, pivot);
	quick_sort(a, b);
	while (*b)
	{
		if ((*a)->rank > (*b)->rank)
			pa(a, b);
		else
		{
			pa(a, b);
			sa(a);
		}
	}
}
