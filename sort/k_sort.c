/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:38 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/22 23:00:03 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	set_location(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lstfist(stack_b);
	while (temp)
	{
		temp->location = i;
		i++;
		temp = temp->next;
	}
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*b;
	int		i;
	int		size;

	i = lstsize(stack_b);
	size = i / 2;
	b = lstfist(stack_b);
	set_location(stack_b);
	ft_printf("A\n");
	while ((*stack_b))
	{
		b = (*stack_b)->next;
		temp = lstfist(stack_b);
		ft_printf("B\n");
		while (temp && temp->index != i)
		{
			ft_printf("C\n");
			ft_printf("nbr: %d\n", temp->nbr);
			ft_printf("index: %d\n", temp->index);
			ft_printf("location: %d\n", temp->location);
			temp = temp->next;
		}
		while (b->index != i)
		{
			ft_printf("D\n");
			ft_printf("size: %d\n", size);
			if (temp->location < size)
			{
				ft_printf("E\n");
				rb(stack_b, 1);
			}
			else
			{
				ft_printf("F\n");
				rrb(stack_b, 1);
			}
		}
		if ((*stack_b)->index == i)
		{
			ft_printf("G\n");
			pa(stack_a, stack_b, 1);
		}
		ft_printf("H\n");
		i--;
	}
}

void	k_sort_(t_stack **stack_a, t_stack **stack_b)
{
	int	push_counter;
	int	range;

	push_counter = 0;
	range = sqrt(lstsize(stack_a)) * 1.5;
	while ((*stack_a))
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
	push_to_a(stack_a, stack_b);
}
