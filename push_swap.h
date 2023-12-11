/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:03:13 by asemsey           #+#    #+#             */
/*   Updated: 2023/12/11 16:45:46 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				pos;
	int				moves;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

// solving
int		issorted(t_list *stack);
t_list	*highest(t_list *node);
t_list	*lowest(t_list *node);
void	set_pos(t_list **stack);
void	set_nodes(t_list **a, t_list **b);
void	mini_sort(t_list **stack);
// algorithm
void	sort(t_list **a, t_list **b);

// moves
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// list functions
t_list	*ft_lst(int *n, unsigned int len);
t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstprint(t_list *lst);
void	free_lst(t_list **lst);
// helpers
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
int		wordcount(const char *str, char c);
char	**free_all(char **strs);
char	**ft_split(const char *str, char c);

#endif