/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:21:13 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/25 15:48:28 by adarmoya         ###   ########.fr       */
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
	if (last == first->next)
	{
		swap(st);
		return ;
	}
	*st = first->next;
	first->next->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

// int	main(void)
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = NULL;
// 	b = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(2));
// 	ft_lstadd_back(&a, ft_lstnew(4));
// 	ft_lstadd_back(&a, ft_lstnew(8));
// 	ft_lstadd_back(&b, ft_lstnew(12));
// 	ft_lstadd_back(&b, ft_lstnew(52));
// 	ft_lstadd_back(&b, ft_lstnew(17));

// 	rr(&a, &b);
// 	t_stack	*tmp = a;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	printf("aaaa\n");
// 	tmp = b;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// }
