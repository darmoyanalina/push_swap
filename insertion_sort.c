/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 17:16:51 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/02 20:21:17 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny(t_stack **st)
{
	if (!st || (*st)->next == NULL)
		return ;
	else if (ft_lstsize(*st) == 2)
	{
		if ((*st)->content > (*st)->next->content)
			sa(st);
	}
	else if (ft_lstsize(*st) == 3)
	{
		while (disorder(*st) != 0)
		{
			if ((*st)->content > ft_lstlast(*st)->content)
				ra(st);
			else if ((*st)->content > (*st)->next->content)
				sa(st);
			else if ((*st)->next->content > ft_lstlast(*st)->content)
				rra(st);
		}
	}
}

int	find_target(t_stack **st, int n)
{
	t_stack		*temp;
    int			count;
    int			value;
    int			pos;

	temp = *st;
	count = 0;
	value = INT_MAX;
	pos = 0;
	while (temp)
	{
		if (temp->content > n && temp->content < value)
		{
			value = temp->content;
			pos = count;
		}
		temp = temp->next;
		count++;
	}
	return (pos);
}

void	insertion_sort(t_stack **st1, t_stack **st2)
{
    int	pos;
    int	pos_bottom;
    int	save_pos;
    int	save_pos_bottom;

	if (ft_lstsize(*st1) <= 3)
		sort_tiny(st1);
	else
	{
		pb(st1, st2);
		pb(st1, st2);
		if (*st2 && (*st2)->next && (*st2)->content < (*st2)->next->content)
			sb(st2);
		//write(1, "loop\n", 5);
		while (*st1)
		{
			if (*st2 && (*st1)->content > (*st2)->content)
				pb(st1, st2);
			else if (*st2 && (*st1)->content < ft_lstlast(*st2)->content)
			{
				pb(st1, st2);
				rb(st2);
			}
			else
			{
				pos = find_target(st2, (*st1)->content);
				pos_bottom = ft_lstsize(*st2) - pos;
				save_pos = pos;
				save_pos_bottom = pos_bottom;
				if (pos < (ft_lstsize(*st2) - pos))
				{
					while (pos)
					{
						rb(st2);
						pos--;
					}
				}
				else
				{
					while (pos_bottom)
					{
						rrb(st2);
						pos_bottom--;
					}
				}
				pb(st1, st2);
				if (save_pos < (ft_lstsize(*st2) - save_pos))
				{
					while (save_pos)
					{
						rrb(st2);
						save_pos--;
					}
				}
				else
				{
					while (save_pos_bottom)
					{
						rb(st2);
						save_pos_bottom--;
					}
				}
			}
		}
		while (*st2)
			pa(st1, st2);
	}
}
