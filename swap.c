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

void	sa(t_stack	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack	**a, t_stack	**b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
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

// 	// printf("%d\n", a->next->content);
// 	// swap(&a);
// 	// sa(&a);
// 	// sb(&b);
// 	ss(&a, &b);
// 	printf("%d\n", b->content);
// 	printf("%d\n", a->content);

// }
