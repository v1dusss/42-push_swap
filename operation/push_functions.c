/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:31:56 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/20 17:20:10 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*a;
	t_stack	*b;

	if (!*stack_b)
		return ;
	temp = b->next;
	if (temp)
		temp->prev = NULL;
	(*stack_a)->next = a;
	(*stack_b)->prev = b;
	*stack_b = temp;
	*stack_a = b;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*a;
	t_stack	*b;

	if (!*stack_a)
		return ;
	temp = a->next;
	if (temp)
		temp->prev = NULL;
	(*stack_b)->next = b;
	(*stack_a)->prev = a;
	*stack_a = temp;
	*stack_b = a;
}
