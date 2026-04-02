/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:18:07 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/31 13:54:55 by neohanya         ###   ########.fr       */
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

	result = 0;
	i = 0;
	while (arg[i])
	{
		if (i > 0 && (arg[i - 1] != ' ' || arg[i + 1] == ' ')
			&& (arg[i] == '+' || arg[i] == '-'))
			return (result);
		if (arg[i] != '-' && arg[i] != '+' && !ft_isval(arg[i]))
			return (result);
		i++;
	}
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

t_stack	*parse(char **arg)
{
	char	**str;
	t_stack	*st;
	int		i;
	int		n;

	if (!validation(*arg))
		err();
	str = ft_split(*arg, ' ');
	i = 0;
	st = NULL;
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
