/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:35:40 by neohanya          #+#    #+#             */
/*   Updated: 2026/03/31 13:53:08 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(t_stack *st)
{
	t_stack	*cur1;
	t_stack	*cur2;

	cur1 = st;
	while (cur1)
	{
		cur2 = cur1->next;
		while (cur2)
		{
			if (cur1->content == cur2->content)
				err();
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
}
