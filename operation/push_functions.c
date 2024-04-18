/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:31:56 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/18 17:42:45 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	if (!*stack_b)
		return ;
	temp_1 = lstfist(stack_a);
	temp_2 = lstfist(stack_b);
	if (temp_1)
	{
		temp_1->prev = temp_2;
		temp_2->next = temp_1;
	}
	*stack_a = temp_2;
	if (temp_2->prev)
		temp_2->prev->next = NULL;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_1;
	t_stack	*temp_2;

	if (!*stack_a)
		return ;
	temp_1 = lstfist(stack_a);
	temp_2 = lstfist(stack_b);
	if (temp_2)
	{
		temp_2->prev = temp_1;
		temp_1->next = temp_2;
	}
	*stack_b = temp_1;
	if (temp_1->prev)
		temp_1->prev->next = NULL;
}
