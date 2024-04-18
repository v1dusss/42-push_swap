/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:43:53 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/18 20:00:14 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (!*stack_a)
		return ;
	temp = lstfist(stack_a);
	temp_2 = temp->next;
	temp_2->prev = NULL;
	temp_2 = lstlast(stack_a);
	temp_2->next = temp;
	temp->prev = temp_2;
	temp->next = NULL;
}

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (!*stack_b)
		return ;
	temp = lstfist(stack_b);
	temp_2 = temp->next;
	temp_2->prev = NULL;
	temp_2 = lstlast(stack_b);
	temp_2->next = temp;
	temp->prev = temp_2;
	temp->next = NULL;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
