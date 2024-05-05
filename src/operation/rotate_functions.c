/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:43:53 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 17:07:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, int print)
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
	if (print && PRINT_OPERATION)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int print)
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
	if (print && PRINT_OPERATION)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print && PRINT_OPERATION)
		ft_printf("rr\n");
}
