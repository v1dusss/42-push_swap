/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:40:39 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/18 23:39:29 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (!*stack_a)
		return ;
	temp = lstlast(stack_a);
	temp_2 = temp->prev;
	temp_2->next = NULL;
	temp_2 = lstfist(stack_a);
	temp_2->prev = temp;
	temp->next = temp_2;
	temp->prev = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (!*stack_b)
		return ;
	temp = lstlast(stack_b);
	temp_2 = temp->prev;
	temp_2->next = NULL;
	temp_2 = lstfist(stack_b);
	temp_2->prev = temp;
	temp->next = temp_2;
	temp->prev = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
