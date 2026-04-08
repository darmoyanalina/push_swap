/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:58 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/08 21:10:34 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./ft_printf.h"

void	print_stack(t_stack *st)
{
	t_stack	*stc;

	stc = st;
	while (stc)
	{
		printf("%d rank = %d\n", stc->content, stc->rank);
		stc = stc->next;
	}
}

void	free_stack(t_stack *st)
{
	t_stack	*tmp;

	tmp = st;
	while (tmp)
	{
		tmp = tmp->next;
		free(st);
		st = tmp;
	}
	st = NULL;
}

void	op_init(t_count *count)
{
	count = malloc(sizeof(t_count));
	if (!count)
		return ;
	count->sa = 0;
	count->sb = 0;
	count->ss = 0;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->rr = 0;
	count->rra = 0;
	count->rrb = 0;
	count->rrr = 0;
	count->overall = 0;
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_count	*count;

	if (argc < 2)
		return (0);
	a = parse(&argv[1]);
	b = NULL;
	count = NULL;
	op_init(count);
	// insertion_sort(&a, &b);
	quick_sort(&a, &b, 0, ft_lstsize(a) - 1);
	// write (1, "a\n", 2);
	// sort_tiny_rev(&a);
	// print_stack(a);
	// write (1, "b\n", 2);
	// print_stack(b);
	free_stack(a);
	return (0);
}
