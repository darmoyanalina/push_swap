/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neohanya <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:49 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/02 20:21:52 by neohanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct d_list
{
	int				content;
	struct d_list	*next;
	struct d_list	*prev;
}	t_stack;

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	push(t_stack **st1, t_stack **st2);
void	pa(t_stack	**a, t_stack **b);
void	pb(t_stack	**a, t_stack **b);
void	swap(t_stack **st);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack	**a, t_stack	**b);
void	rotate(t_stack **st);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	r_rotate(t_stack **st);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	err(void);
int		ft_lstsize(t_stack *lst);
int		ft_atoi(const char *nptr);
int		validation(const char *arg);
int		ft_isval(int c);
float	disorder(t_stack *st);
char	**ft_split(char const *s, char c);
t_stack	*parse(char **arg);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	check_duplicates(t_stack *st);
void	sort_tiny(t_stack **st);
int		find_target(t_stack **st, int n);
void	insertion_sort(t_stack **st1, t_stack **st2);

#endif
