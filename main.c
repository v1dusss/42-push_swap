/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 17:05:25 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = lstfist(stack_a);
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// stack_a = malloc(sizeof(t_stack));
	// stack_b = malloc(sizeof(t_stack));
	push_swap_parse(argc, argv, &stack_a);
	get_index(&stack_a);
	my_own_sort(&stack_a, &stack_b);
	// test(&stack_a);
	return (0);
}
