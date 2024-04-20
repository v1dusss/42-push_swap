/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:40:39 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/20 18:00:33 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	a = *stack_a;
	temp = lstlast(stack_a);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = a;
	a->prev = temp;
	*stack_a = temp;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*b;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	b = *stack_b;
	temp = lstlast(stack_b);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = b;
	b->prev = temp;
	*stack_b = temp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
