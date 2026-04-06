/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 23:05:35 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/05 23:05:35 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tiny_quick(t_stack **st, t_stack **st1, int size)
{
	if (size < 2)
		return ;
	else if (size == 2)
	{
		if ((*st)->content > (*st)->next->content)
			sa(st);
	}
	else if (size == 3)
	{
		if ((*st)->content > (*st)->next->content)
			sa(st);
		if ((*st)->next->content > (*st)->next->next->content)
		{
			pb(st, st1);
			sa(st);
			pa(st, st1);
		}
		if ((*st)->content > (*st)->next->content)
			sa(st);
	}
}

void	sort_tiny_quick_rev(t_stack **st, t_stack **st1, int size)
{
	if (size < 2)
		return ;
	else if (size == 2)
	{
		if ((*st1)->content < (*st1)->next->content)
			sb(st1);
	}
	else if (size == 3)
	{
		if ((*st1)->content < (*st1)->next->content)
			sb(st1);
		if ((*st1)->next->content < (*st1)->next->next->content)
		{
			pa(st, st1);
			sb(st1);
			pb(st, st1);
		}
		if ((*st1)->content < (*st1)->next->content)
			sb(st1);
	}
	
}
