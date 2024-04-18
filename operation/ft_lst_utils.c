/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:21 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/18 19:50:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstfist(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->prev)
	{
		tmp = tmp->prev;
	}
	return (tmp);
}

t_stack	*lstlast(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}
