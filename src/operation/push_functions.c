/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 21:31:56 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 17:07:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*a;
	t_stack	*b;

	if (!*stack_b)
		return ;
	a = *stack_a;
	b = *stack_b;
	temp = b->next;
	if (temp)
		temp->prev = NULL;
	b->next = a;
	if (a)
		a->prev = b;
	*stack_a = b;
	*stack_b = temp;
	if (print && PRINT_OPERATION)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*a;
	t_stack	*b;

	if (!*stack_a)
		return ;
	a = *stack_a;
	b = *stack_b;
	temp = a->next;
	if (temp)
		temp->prev = NULL;
	a->next = b;
	if (b)
		b->prev = a;
	*stack_a = temp;
	*stack_b = a;
	if (print && PRINT_OPERATION)
		ft_printf("pb\n");
}
