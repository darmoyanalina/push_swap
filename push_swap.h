/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adarmoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 18:33:49 by adarmoya          #+#    #+#             */
/*   Updated: 2026/04/10 17:58:45 by adarmoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
#include "ft_printf/ft_printf.h"

typedef struct d_list
{
	int				content;
	int				rank;
	struct d_list	*next;
	struct d_list	*prev;
}	t_stack;

typedef struct ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	overall;
}	t_count;

typedef struct stacks
{
	t_stack	**a;
	t_stack	**b;
}	t_stacks;

typedef struct algs
{
	int algorithm;
	int adaptive;
	int bench;
}	t_alg;

void		print_stack(t_stack *st);

void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		push(t_stack **st1, t_stack **st2);
void		pa(t_stack	**a, t_stack **b, t_count *count);
void		pb(t_stack	**a, t_stack **b, t_count *count);
void		swap(t_stack **st);
void		sa(t_stack	**a, t_count *count);
void		sb(t_stack **b, t_count *count);
void		ss(t_stack	**a, t_stack	**b, t_count *count);
void		rotate(t_stack **st);
void		ra(t_stack **a, t_count *count);
void		rb(t_stack **b, t_count *count);
void		rr(t_stack **a, t_stack **b, t_count *count);
void		r_rotate(t_stack **st);
void		rra(t_stack **a, t_count *count);
void		rrb(t_stack **b, t_count *count);
void		rrr(t_stack **a, t_stack **b, t_count *count);
void		err(void);
void		check_duplicates(t_stack *st);
void		sort_tiny(t_stack **st, t_count *count);
void		insertion_sort(t_stack **st1, t_stack **st2, t_count *count);
void		quick_sort(t_stacks *stacks, int start, int end, t_count *count);
void		check_dup_f(void);
void		free_stack(t_stack *st, t_stacks *sts);
void		ranking(t_stack *st);
void		sort_array(int *contents, int size);
void		bench(t_count *count, float disorder, t_alg *c_algs);
void		call_sort(t_stacks *stacks, t_alg *c_algs, t_count *count);
void		choose_alg(t_stack *a, t_stack *b, char **argv, t_count *count);
void		medium_sort(t_stack **a, t_stack **b, t_count *count);
int			*get_array(t_stack *st);
int			ft_lstsize(t_stack *lst);
int			ft_atoi(const char *nptr);
int			validation(const char *arg);
int			ft_isval(int c);
int			ft_strcmp(const char *s1, const char *s2);
int			find_target(t_stack **st, int n);
int			check_flags(char *str, t_alg **c_algs);
int			sort(t_stacks *stacks, int start, int end, t_count *count);
int			get_chunk_size(int max_index);
float		disorder(t_stack *st);
char		**ft_split(char const *s, char c);
t_stack		*parse(char **arg, t_alg **c_algs);
t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
t_count		*op_init(t_count *count);
t_stacks	*stacks_init(t_stacks *stacks, t_stack **a, t_stack **b);
t_alg		*alg_init(t_alg *c_algs);
t_alg		*modify(t_alg *c_algs, float dis);

#endif
