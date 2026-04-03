/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:58 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/03 19:00:10 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *st)
{
	t_stack	*stc;

	stc = st;
	while (stc)
	{
		printf("%d\n", stc->content);
		stc = stc->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse(&argv[1]);
	b = NULL;
	insertion_sort(&a, &b);
	print_stack(a);
	return (0);
}
