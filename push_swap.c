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

t_count	*op_init(t_count *count)
{
	count = malloc(sizeof(t_count));
	if (!count)
		exit(0);
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
	return (count);
}

t_stacks	*stacks_init(t_stacks *stacks, t_stack **a, t_stack **b)
{
	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		exit(0);
	stacks->a = a;
	stacks->b = b;
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stacks	*stacks;
	t_count	*count;
	int		dis;

	if (argc < 2)
		return (0);
	a = parse(&argv[1]);
	b = NULL;
	count = NULL;
	stacks = NULL;
	count = op_init(count);
	stacks = stacks_init(stacks, &a, &b);
	dis = disorder(a);
	// insertion_sort(&a, &b);
	quick_sort(stacks, 0, ft_lstsize(a) - 1, count);
	// bench(count, dis);
	// write (1, "a\n", 2);
	// print_stack(a);
	// write (1, "b\n", 2);
	// print_stack(b);
	free_stack(a);
	return (0);
}
