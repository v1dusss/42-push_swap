/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/24 20:04:06 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = lstfirst(stack_a);
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

void	clear_stack(t_stack **stack)
{
	t_stack	*tmp;

	while ((*stack)->next)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	free(*stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push_swap_parse(argc, argv, &stack_a);
	get_index(&stack_a);
	if (lstsize(&stack_a) == 3)
		three_sort(&stack_a);
	else
		k_sort_(&stack_a, &stack_b);
	// test(&stack_a);
	clear_stack(&stack_a);
	return (0);
}
