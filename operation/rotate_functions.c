/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:43:53 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/20 17:57:20 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	a = *stack_a;
	temp = a->next;
	temp->prev = NULL;
	a->next = NULL;
	(*stack_a) = temp;
	temp = lstlast(stack_a);
	temp->next = a;
	a->prev = temp;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*b;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	b = *stack_b;
	temp = b->next;
	temp->prev = NULL;
	b->next = NULL;
	(*stack_b) = temp;
	temp = lstlast(stack_b);
	temp->next = b;
	b->prev = temp;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
