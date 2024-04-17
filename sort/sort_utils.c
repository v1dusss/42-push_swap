/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/17 16:24:25 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_place(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = lstfist(stack);
	while (tmp)
	{
		tmp2 = lstfist(stack);
		i = 1;
		while (tmp2)
		{
			if (tmp2->nbr < tmp->nbr)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->place = i;
		tmp = tmp->next;
	}
}
