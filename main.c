/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/28 17:03:09 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (lstsize(&stack_a) == 2)
		sa(&stack_a, 1);
	else if (lstsize(&stack_a) == 3)
		three_sort(&stack_a);
	else if (lstsize(&stack_a) == 5)
		five_sort(&stack_a, &stack_b);
	else
		k_sort_(&stack_a, &stack_b);
	lstclear(&stack_a);
	return (0);
}
