/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_own_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:54:59 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/19 02:06:17 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_own_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*temp;
	t_stack *temp_2;

	i = 1;
	temp = lstfist(stack_a);
	temp_2 = lstfist(stack_b);
	ft_printf("a\n");
	while (temp)
	{
		if (temp->place == i)
		{
			pb(&temp, &temp_2);
			i++;
		}
		else
		{
			ra(&temp);
		}
		temp = lstfist(&temp);
		sleep(1);
		ft_printf("i = %d\n", i);
		ft_printf("temp->place = %d\n", temp->place);
		ft_printf("temp->nbr = %d\n", temp->nbr);
		ft_printf("====================================\n");
	}
	ft_printf("b\n");
	while (lstfist(&temp_2))
	{
		pa(&temp, &temp_2);
	}
}
