/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:23:15 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/25 15:39:40 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack **st)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!st || !*st || !(*st)->next)
		return ;
	tmp1 = *st;
	tmp2 = (*st)->next;
	*st = tmp2;
	(*st)->prev = NULL;
	tmp1->next = (*st)->next;
	(*st)->next = tmp1;
	if (tmp1->next)
		tmp1->next->prev = tmp1;
}

void	sa(t_stack	**a)
{
	swap(a);
}

void	sb(t_stack **b)
{
	swap(b);
}

void	ss(t_stack	**a, t_stack	**b)
{
	sa(a);
	sb(b);
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
