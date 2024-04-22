/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:38 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 21:59:17 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	k_sort_(t_stack **stack_a, t_stack **stack_b)
{
	int	push_counter;
	int	range;

	push_counter = 0;
	range = sqrt(lstsize(stack_a)) * 1.5;
	while (stack_a)
	{
		if ((*stack_a)->index <= push_counter)
		{
			pb(stack_a, stack_b, 1);
			rb(stack_b, 1);
			push_counter++;
		}
		else if ((*stack_a)->index < range + push_counter)
		{
			pb(stack_a, stack_b, 1);
			push_counter++;
		}
		else
		{
			ra(stack_a, 1);
		}
	}
	// push_to_a(stack_a, stack_b);
}
