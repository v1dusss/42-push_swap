/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:40:39 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 17:07:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int print)
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
	if (print && PRINT_OPERATION)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int print)
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
	if (print && PRINT_OPERATION)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (print && PRINT_OPERATION)
		ft_printf("rrr\n");
}
