/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 14:58:09 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/09 18:37:24 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_stack *st)
{
	int		total_pairs;
	float	mistakes;
	t_stack	*cur1;
	t_stack	*cur2;

	mistakes = 0;
	total_pairs = 0;
	cur1 = st;
	cur2 = cur1->next;
	while (cur1->next)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			total_pairs++;
			if (cur1->rank > cur2->rank)
				mistakes++;
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
	return (mistakes / total_pairs);
}
