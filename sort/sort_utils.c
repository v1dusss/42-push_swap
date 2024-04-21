/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:49:01 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/21 11:36:19 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_index(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = lstfist(stack);
	while (tmp)
	{
		tmp2 = lstfist(stack);
		i = 0;
		while (tmp2)
		{
			if (tmp2->nbr < tmp->nbr)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}
