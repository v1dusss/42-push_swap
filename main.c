/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/25 16:27:02 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = lstfirst(stack_a);
	ft_putstr_fd("*******************\n", 1);
	while (tmp)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	ft_putstr_fd("*******************\n", 1);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
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
