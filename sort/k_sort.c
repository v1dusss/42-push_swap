/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 20:28:38 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/23 19:45:38 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

void	set_location(t_stack **stack_b)
{
	t_stack	*temp;
	int		i;

	i = 1;
	temp = lstfist(stack_b);
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
	temp = lstfist(stack_b);
	while (temp->index != size)
	{
		sleep(1);
		ft_printf("---------\n");
		ft_printf("temp->nbr: %d\n", temp->nbr);
		ft_printf("temp->index: %d\n", temp->index);
		ft_printf("temp->location: %d\n", temp->location);
		ft_printf("size: %d\n", size);
		if (location >= (size / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
		temp = lstfist(stack_b);
		i++;
		if (i > 10)
			exit(1);
	}
	ft_printf("++++++++++++++++++++++\n");
	return (temp);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		size;
	int		i;
	int		location;

	i = 0;
	location = 0;
	size = lstsize(stack_b);
	while ((*stack_b))
	{
		set_location(stack_b);
		temp = lstfist(stack_b);
		ft_printf("==A==\n");
		if (temp->index != size)
		{
			ft_printf("==B==\n");
			while (temp->index == size)
			{
				ft_printf("==C==\n");
				temp = temp->next;
			}
			ft_printf("==D==\n");
			location = temp->location;
			ft_printf("location: %d\n", location);
			temp = rotate_to(stack_b, size, location);
			ft_printf("==E==\n");
			ft_printf("temp->index: %d\n", temp->index);
			ft_printf("size: %d\n", size);
		}
		if (temp->index == size)
		{
			ft_printf("==F==\n");
			pa(stack_a, stack_b, 1);
		}
		else
		{
			ft_printf("Konnte nicht die richtige Zahl finden zum puschen");
			exit(1);
		}
		ft_printf("==G==\n");
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
