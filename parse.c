/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:18:07 by adarmoya          #+#    #+#             */
/*   Updated: 2026/03/25 20:56:30 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isval(int c)
{
	if ((c >= '0' && c <= '9') ||
		(c >= 9 && c <= 13) || c == ' ')
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
		if (i > 0 && arg[i - 1] != ' ' &&
			(arg[i] == '+' || arg[i] == '-'))
			return (result);
		if (arg[i] != '-' && arg[i] != '+' &&
			!ft_isval(arg[i]))
			return (result);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	number;
	int	i;
	int	sign;

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
	return (number);
}

t_stack	*parse(char **arg)
{
	char	**str;
	t_stack	*st;
	int		i;
	int		n;

	if (!validation(*arg))
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	str = ft_split(*arg, ' ');
	i = 0;
	st = NULL;
	n = 0;
	while (str[i])
	{
		n = ft_atoi(str[i]);
		// n-i validation
		ft_lstadd_back(&st, ft_lstnew(n));
		i++;
	}
	return (st);
}

// int	main(void)
// {
// 	char *str = "-5 2   	";
// 	t_stack	*st = parse(&str);
// 	t_stack	*tmp = st;
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->content);
// 		tmp = tmp->next;
// 	}
// 	return (0);
// }
