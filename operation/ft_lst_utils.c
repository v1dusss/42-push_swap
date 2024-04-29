/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:21 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/29 19:12:46 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lstfirst(t_stack **stack)
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

t_stack	*lstnew(int data)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	stack->nbr = data;
	stack->next = NULL;
	stack->index = 0;
	return (stack);
}

void	lstclear(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		exit(0);
	if (lstsize(stack) < 2)
	{
		free(*stack);
		exit(0);
	}
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	free(*stack);
}
