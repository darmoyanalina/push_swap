/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:35:40 by neohanya          #+#    #+#             */
/*   Updated: 2026/04/11 13:19:16 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (!s1[i] && s2[i])
		return (0 - s2[i]);
	if (s1[i] && !s2[i])
		return (s1[i]);
	return (0);
}

void	check_duplicates(t_stack *st, t_alg **c_algs, t_count **count)
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
				err(*c_algs, *count);
			cur2 = cur2->next;
		}
		cur1 = cur1->next;
	}
}

void	check_dup_f(t_alg **c_algs, t_count **count)
{
	static int	checked;

	checked++;
	if (checked > 1)
		err(*c_algs, *count);
}

int	check_flags(char *str, t_alg **c_algs, t_count **count)
{
	static int	bench;

	if (!ft_strcmp(str, "--simple"))
		return (check_dup_f(c_algs, count), (*c_algs)->algorithm = 1);
	else if (!ft_strcmp(str, "--medium"))
		return (check_dup_f(c_algs, count), (*c_algs)->algorithm = 2);
	else if (!ft_strcmp(str, "--complex"))
		return (check_dup_f(c_algs, count), (*c_algs)->algorithm = 3);
	else if (!ft_strcmp(str, "--adaptive"))
		return (check_dup_f(c_algs, count), (*c_algs)->adaptive = 1);
	if (!ft_strcmp(str, "--bench"))
	{
		(*c_algs)->bench = 1;
		bench++;
		if (bench > 1)
			err(*c_algs, *count);
		return (5);
	}
	return (0);
}
