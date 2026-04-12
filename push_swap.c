/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:58 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/12 17:13:10 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *st)
{
	t_stack	*stc;

	stc = st;
	while (stc)
	{
		ft_printf("%d rank = %d\n", stc->content, stc->rank);
		stc = stc->next;
	}
}

void	free_stack(t_stack *st, t_stacks *sts)
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
	if (sts)
		free(sts);
	sts = NULL;
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

void	free_algs(t_alg *c_algs, t_count *count)
{
	free(c_algs);
	free(count);
	c_algs = NULL;
	count = NULL;
}
