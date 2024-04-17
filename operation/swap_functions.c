/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:16:34 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/17 21:34:59 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	temp_1 = lstfist(stack_a);
	temp_2 = temp_1->next;
	if (temp_1->nbr > temp_2->nbr)
	{
		temp_1->next = temp_2->next;
		temp_2->prev = temp_1->prev;
		temp_1->prev = temp_2;
		temp_2->next = temp_1;
		if (temp_1->next)
			temp_1->next->prev = temp_1;
		if (temp_2->prev)
			temp_2->prev->next = temp_2;
		if (temp_1 == *stack_a)
			*stack_a = temp_2;
	}
}

void	sb(t_stack **stack_b)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	temp_1 = lstfist(stack_b);
	temp_2 = temp_1->next;
	if (temp_1->nbr < temp_2->nbr)
	{
		temp_1->next = temp_2->next;
		temp_2->prev = temp_1->prev;
		temp_1->prev = temp_2;
		temp_2->next = temp_1;
		if (temp_1->next)
			temp_1->next->prev = temp_1;
		if (temp_2->prev)
			temp_2->prev->next = temp_2;
		if (temp_1 == *stack_b)
			*stack_b = temp_2;
	}
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
