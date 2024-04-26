/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:20 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/26 16:06:12 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				location;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

# define PRINT_OPERATION 1
# define PRINT_INPUT 0

void				test(t_stack **stack_a);
void				print_error(char **split);
void				push_swap_parse(int argc, char **argv, t_stack **stack_a);
void				loop_parse(t_stack **stack_a, char **split, int j, int x);
void				get_index(t_stack **stack);
void				three_sort(t_stack **stack_a);
void				five_sort(t_stack **stack_a, t_stack **stack_b);
void				my_own_sort(t_stack **stack_a, t_stack **stack_b);
void				k_sort_(t_stack **stack_a, t_stack **stack_b);
void				set_location(t_stack **stack_b);
t_stack				*lstfirst(t_stack **stack);
t_stack				*lstlast(t_stack **stack);
int					lstsize(t_stack **stack);
t_stack				*push_swap_lstnew(int data);
void				clear_stack(t_stack **stack);
// void				bubble_sort(t_stack **stack);
void				sa(t_stack **stack_a, int print);
void				sb(t_stack **stack_b, int print);
void				ss(t_stack **stack_a, t_stack **stack_b, int print);
void				pa(t_stack **stack_a, t_stack **stack_b, int print);
void				pb(t_stack **stack_a, t_stack **stack_b, int print);
void				ra(t_stack **stack_a, int print);
void				rb(t_stack **stack_b, int print);
void				rr(t_stack **stack_a, t_stack **stack_b, int print);
void				rra(t_stack **stack_a, int print);
void				rrb(t_stack **stack_b, int print);
void				rrr(t_stack **stack_a, t_stack **stack_b, int print);

#endif
