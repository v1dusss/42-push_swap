/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:54:59 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/21 14:33:18 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_own_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack *a;

	i = 0;
	a = lstfist(stack_a);
	while (lstsize(stack_a) > 1)
	{
		a = lstfist(stack_a);
		if (a->index == i)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
		{
			ra(stack_a, 1);
		}
	}
	while (lstsize(stack_b) > 0)
	{
		pa(stack_a, stack_b, 1);
	}
}
