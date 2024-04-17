/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:20 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/17 21:33:58 by vsivanat         ###   ########.fr       */
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
	int				place;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

void				push_swap_parse(int argc, char **argv, t_stack **stack_a);
void				get_place(t_stack **stack);
t_stack				*lstfist(t_stack **stack);
void				bubble_sort(t_stack **stack);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);

#endif
