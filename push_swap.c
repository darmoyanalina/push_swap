/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:58 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/05 18:54:23 by adarmoya         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse(&argv[1]);
	b = NULL;
	// insertion_sort(&a, &b);
	quick_sort(&a, &b);
	write (1, "a\n", 2);
	// sort_tiny_rev(&a);
	print_stack(a);
	write (1, "b\n", 2);
	print_stack(b);
	free_stack(a);
	return (0);
}
