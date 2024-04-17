/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:37:16 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/17 16:55:46 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack) // with out operation functions
{
	t_stack *tmp;
	t_stack *tmp2;
	int temp_nbr;
	int temp_place;

	tmp = lstfist(stack);
	while (tmp)
	{
		tmp2 = lstfist(stack);
		while (tmp2->next)
		{
			if (tmp2->nbr > tmp2->next->nbr)
			{
				temp_nbr = tmp2->nbr;
				tmp2->nbr = tmp2->next->nbr;
				tmp2->next->nbr = temp_nbr;
				temp_place = tmp2->place;
				tmp2->place = tmp2->next->place;
				tmp2->next->place = temp_place;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}
