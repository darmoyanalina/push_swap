/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:37:39 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/04 16:10:19 by adarmoya         ###   ########.fr       */
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
	// if ((middle > st->content && middle < ft_lstlast(st)->content) ||
	// 	(middle < st->content && middle > ft_lstlast(st)->content))
	// {
		i = 0;
		while (i < middle)
		{
			piv = piv->next;
			i++;
		}
	// }
	// else if ((middle > st->content && st->content < ft_lstlast(st)->content) ||
	// 	(middle < st->content && st->content > ft_lstlast(st)->content))
	// 	piv = ft_lstlast(st);
	return (piv->content);
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
	a_top = (*a)->content;
	if (a_top <= pivot)
		pb(a, b);
	else
		ra(a);
	while (*a && a_top != (*a)->content)
	{
		if (*b && a_top == (*b)->content)
			a_top = ((*a)->content);
		if ((*a)->content <= pivot)
			pb(a, b);
		else
			ra(a);
	}
	if (*a)
		printf("a%d\n", (*a)->content);
}

void	quick_sort(t_stack **a, t_stack **b)
{
	int	pivot;

	if (!disorder(*a))
		return ;
	while (*a)
	{
		pivot = pivot_val(*a);
		// if (*a && !(*a)->next)
		// 	pivot = (*a)->content;
		q_sort_helper_a(a, b, pivot);
		printf ("pivot = %d\n", pivot);
	}
	while (*b)
	{
		pivot = pivot_val(*b);
		// if (*b && !(*b)->next)
		// 	pivot = (*b)->content;
		q_sort_helper_b(a, b, pivot);
		printf ("bpivot = %d\n", pivot);
	}
	// quick_sort(a, b);
}
