/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:16:34 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/20 17:44:07 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	a = stack_a;
	temp = a->next;
	temp->prev = NULL;
	a->next = temp->next;
	temp->next = a;
	a->prev = temp;
	*stack_a = temp;
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*b;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	b = stack_b;
	temp = b->next;
	temp->prev = NULL;
	b->next = temp->next;
	temp->next = b;
	b->prev = temp;
	*stack_b = temp;
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
