/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.4bin.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 18:04:33 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*temp2;

	temp = lstfist(stack);
	while (temp)
	{
		temp2 = lstfist(stack);
		i = 0;
		while (temp2)
		{
			if (temp2->nbr < temp->nbr)
				i++;
			temp2 = temp2->next;
		}
		temp->index = i;
		temp = temp->next;
	}
}

void	three_sort(t_stack **stack_a)
{
	t_stack	*a;

	a = lstfist(stack_a);
	if (a->index == 1 && a->next->index == 0)
		sa(stack_a, 1);
	else if (a->index == 2 && a->next->index == 0)
		ra(stack_a, 1);
	else if (a->index == 2 && a->next->index == 1)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a->index == 1 && a->next->index == 2)
		rra(stack_a, 1);
	else if (a->index == 0 && a->next->index == 2)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
}
