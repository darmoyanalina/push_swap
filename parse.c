/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:18:07 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/11 13:17:59 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(t_alg *c_algs, t_count *count)
{
	write (2, "Error\n", 6);
	free_algs(c_algs, count);
	exit(1);
}

int	ft_isval(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 9 && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

int	validation(const char *arg)
{
	int	result;
	int	i;
	int	empty;

	result = 0;
	i = 0;
	empty = 0;
	while (arg[i])
	{
		if (i > 0 && (arg[i - 1] != ' ' || arg[i + 1] == ' ')
			&& (arg[i] == '+' || arg[i] == '-'))
			return (result);
		if (arg[i] != '-' && arg[i] != '+' && !ft_isval(arg[i]))
			return (result);
		if ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
			empty++;
		i++;
	}
	if (empty == i)
		return (result);
	return (1);
}

int	ft_atoi(const char *nptr, t_alg **c_algs, t_count **count)
{
	long	number;
	int		i;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	number *= sign;
	if (number > INT_MAX || number < INT_MIN)
		err(*c_algs, *count);
	return ((int)number);
}

t_stack	*parse(char **arg, t_alg **c_algs, t_count **count)
{
	char	**str;
	char	**argv;
	t_stack	*st;
	int		i;
	int		n;

	argv = arg;
	st = NULL;
	while (*argv)
	{
		if (!check_flags(*argv, c_algs, count))
		{
			if (!validation(*argv))
				err(*c_algs, *count);
			str = ft_split(*argv, ' ');
			i = 0;
			n = 0;
			while (str[i])
			{
				n = ft_atoi(str[i], c_algs, count);
				ft_lstadd_back(&st, ft_lstnew(n));
				i++;
			}
			i = 0;
			while (str[i])
				free(str[i++]);
			free(str);
			check_duplicates(st, c_algs, count);
		}
		argv++;
	}
	ranking(st);
	return (st);
}
