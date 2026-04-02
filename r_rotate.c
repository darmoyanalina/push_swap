/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 15:48:43 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/02 14:59:26 by neohanya         ###   ########.fr       */
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
	if (last->prev == first)
	{
		swap(st);
		return ;
	}
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*st = last;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}

// int	main(void)
// {
// 	t_stack *a;
// 	t_stack *b;

// 	a = NULL;
// 	b = NULL;
// 	ft_lstadd_back(&a, ft_lstnew(2));
// 	ft_lstadd_back(&a, ft_lstnew(4));
// 	ft_lstadd_back(&a, ft_lstnew(54));
// 	ft_lstadd_back(&a, ft_lstnew(8));
// 	ft_lstadd_back(&b, ft_lstnew(12));
// 	ft_lstadd_back(&b, ft_lstnew(52));
// 	ft_lstadd_back(&b, ft_lstnew(22));
// 	ft_lstadd_back(&b, ft_lstnew(17));

// 	rrr(&a, &b);
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
