/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:54:59 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/21 23:20:33 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_own_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;

	i = 0;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->index == i++)
			pb(stack_a, stack_b, 1);
		else if (i--)
			ra(stack_a, 1);
	}
	while ((*stack_b)->next)
		pa(stack_a, stack_b, 1);
}
