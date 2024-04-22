/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:16:34 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 17:07:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	t_stack	*temp;
	t_stack	*a;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	a = (*stack_a);
	temp = a->next;
	temp->prev = NULL;
	a->next = temp->next;
	temp->next = a;
	a->prev = temp;
	*stack_a = temp;
	if (print && PRINT_OPERATION)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int print)
{
	t_stack	*temp;
	t_stack	*b;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	b = (*stack_b);
	temp = b->next;
	temp->prev = NULL;
	b->next = temp->next;
	temp->next = b;
	b->prev = temp;
	*stack_b = temp;
	if (print && PRINT_OPERATION)
		ft_printf("sb\n");
}
void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print && PRINT_OPERATION)
		ft_printf("ss\n");
}
