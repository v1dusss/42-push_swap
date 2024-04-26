/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/26 16:19:11 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **stack)
{
	int		i;
	t_stack	*temp;
	t_stack	*temp2;

	temp = lstfirst(stack);
	while (temp)
	{
		temp2 = lstfirst(stack);
		i = 1;
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

	a = lstfirst(stack_a);
	if (a->index == 2 && a->next->index == 1)
		sa(stack_a, 1);
	else if (a->index == 3 && a->next->index == 1)
		ra(stack_a, 1);
	else if (a->index == 3 && a->next->index == 2)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (a->index == 2 && a->next->index == 3)
		rra(stack_a, 1);
	else if (a->index == 1 && a->next->index == 3)
	{
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
}

void	five_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;

	i = 0;
	while (i < 2)
	{
		temp = lstfirst(stack_a);
		if (temp->index == 1 || temp->index == 2)
		{
			pb(stack_a, stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
	if (lstfirst(stack_b)->index == 1)
		sb(stack_b, 1);
	get_index(stack_a);
	three_sort(stack_a);
	pa(stack_a, stack_b, 1);
	pa(stack_a, stack_b, 1);
}
