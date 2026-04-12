/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:17:57 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/12 18:15:59 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_alg	*alg_init(t_alg *c_algs)
{
	c_algs = malloc(sizeof(t_alg));
	if (!c_algs)
		exit(0);
	c_algs->algorithm = 0;
	c_algs->bench = 0;
	c_algs->adaptive = -1;
	return (c_algs);
}

t_alg	*modify(t_alg *c_algs, float dis)
{
	c_algs->adaptive = 1;
	if (dis < 0.2)
		c_algs->algorithm = 1;
	else if (dis >= 0.2 && dis < 0.5)
		c_algs->algorithm = 2;
	else if (dis >= 0.5)
		c_algs->algorithm = 3;
	return (c_algs);
}

void	call_sort(t_stacks *stacks, t_alg *c_algs, t_count *count)
{
	float		dis;

	dis = disorder(*(stacks->a));
	if (dis && c_algs->algorithm == 1)
		insertion_sort(stacks->a, stacks->b, count);
	else if (dis && c_algs->algorithm == 2)
		medium_sort(stacks, count);
	else if (dis && c_algs->algorithm == 3)
		quick_sort(stacks, 0, ft_lstsize(*(stacks->a)) - 1, count);
	else
	{
		c_algs = modify(c_algs, dis);
		if (ft_lstsize(*(stacks->a)) <= 5 || (dis > 0 && dis < 0.2))
			insertion_sort(stacks->a, stacks->b, count);
		else if (dis >= 0.2 && dis < 0.5)
			medium_sort(stacks, count);
		else if (dis >= 0.5)
			quick_sort(stacks, 0, ft_lstsize(*(stacks->a)) - 1, count);
	}
	if (c_algs->bench)
		bench(count, dis, c_algs);
	if (!dis)
		return ;
}

void	choose_alg(t_stack *a, t_stack *b, char **argv, t_count *count)
{
	t_stacks	*stacks;
	t_alg		*c_algs;

	stacks = NULL;
	c_algs = NULL;
	c_algs = alg_init(c_algs);
	a = parse(&argv[1], &c_algs, &count);
	stacks = stacks_init(stacks, &a, &b);
	call_sort(stacks, c_algs, count);
	free_stack(a, stacks);
	free_algs(c_algs, count);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_count		*count;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	count = NULL;
	count = op_init(count);
	choose_alg(a, b, argv, count);
	return (0);
}
