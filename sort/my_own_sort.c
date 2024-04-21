/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:54:59 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/21 11:36:14 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_own_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	//t_stack	*temp;
	t_stack *a;
	t_stack *b;

	i = 0;
	a = lstfist(stack_a);
	b = lstfist(stack_b);
	ft_printf("A\n");
	while (lstsize(stack_a) > 1)
	{
		a = lstfist(stack_a);
		if (a->index == i)
		{
			pb(stack_a, stack_b);
			b = lstfist(stack_b);
			i++;
			ft_printf("pb\n");
		}
		else
		{
			ra(stack_a);
			ft_printf("ra\n");
			sleep(1);
		}
	}
	ft_printf("B\n");
	while (lstsize(stack_b) > 0)
	{
		pa(stack_a, stack_b);
		ft_printf("pa\n");
		a = lstfist(stack_a);
		b = lstfist(stack_b);
	}
	ft_printf("C\n");
	i = 0;
	a = lstfist(stack_a);
	b = lstfist(stack_b);
	while (++i <= 10)
	{
		if (a)
		{
			ft_printf("%d (%d)\t|", a->nbr,a->index);
			a = a->next;
		}
		else
			ft_printf("-\t|");
		sleep(1);
		if (b)
		{
			ft_printf("\t%d (%d)\n", a->nbr, b->index);
			b = b->next;
		}
		else
			ft_printf("\t-\n");
		sleep(1);
	}
	ft_printf("D\n");
}
