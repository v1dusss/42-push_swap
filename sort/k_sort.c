/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:38 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/25 16:46:59 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_location(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = lstfirst(stack_b);
	while (temp)
	{
		temp->location = i;
		i++;
		temp = temp->next;
	}
}

t_stack	*rotate_to(t_stack **stack_b, int size, int location)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lstfirst(stack_b);
	while (temp->index != size)
	{
		if (location >= (size / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
		temp = lstfirst(stack_b);
		i++;
	}
	return (temp);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;
	int		location;

	location = 0;
	size = lstsize(stack_b);
	while ((*stack_b))
	{
		set_location(stack_b);
		temp = lstfirst(stack_b);
		if (temp->index != size)
		{
			while (temp->index != size)
			{
				temp = temp->next;
			}
			location = temp->location;
			temp = rotate_to(stack_b, size, location);
		}
		if (temp->index == size)
			pa(stack_a, stack_b, 1);
		size--;
	}
}

float	sqrt_custom(int size)
{
	float	guess;
	float	epsilon;
	float	diff;

	if (size < 0)
		return (-1.0);
	guess = size / 2.0;
	epsilon = 0.0001;
	while (1)
	{
		diff = guess * guess - size;
		if (diff < 0)
			diff = -diff;
		if (diff <= epsilon)
			break ;
		guess = (guess + size / guess) / 2.0;
	}
	return (guess);
}

void	k_sort_(t_stack **stack_a, t_stack **stack_b)
{
	int		push_counter;
	float	range;

	push_counter = 0;
	range = sqrt_custom(lstsize(stack_a)) * 2;
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
			ra(stack_a, 1);
	}
	push_to_a(stack_a, stack_b);
	// ft_printf("end of k_sort\n");
}
