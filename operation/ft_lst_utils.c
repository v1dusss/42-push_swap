/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:21 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/20 18:08:38 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstfist(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (NULL);
	while (temp->prev)
	{
		temp = temp->prev;
	}
	return (temp);
}

t_stack	*lstlast(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

int	lstsize(t_stack **stack)
{
	t_stack	*temp;
	int		count;

	temp = *stack;
	count = 0;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
