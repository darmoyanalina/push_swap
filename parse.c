/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:18:07 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/05 18:50:40 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err(void)
{
	write (2, "Error\n", 6);
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

int	ft_atoi(const char *nptr)
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
		err();
	return ((int)number);
}

t_stack	*parse(char **arg, t_alg **c_algs)
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
		if (!check_flags(*argv, c_algs))
		{
			if (!validation(*argv))
				err();
			str = ft_split(*argv, ' ');
			i = 0;
			n = 0;
			while (str[i])
			{
				n = ft_atoi(str[i]);
				ft_lstadd_back(&st, ft_lstnew(n));
				i++;
			}
			i = 0;
			while (str[i])
				free(str[i++]);
			free(str);
			check_duplicates(st);
			argv++;
		}
		else
		{
			argv++;
		}
	}
	ranking(st);
	return (st);
}

// int	main(void)
// {
// 	char *str = "553000";
// 	t_stack	*st = parse(&str);
// 	t_stack	*tmp = st;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
