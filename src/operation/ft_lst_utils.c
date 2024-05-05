/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:10:21 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/29 21:17:12 by vsivanat         ###   ########.fr       */
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

t_stack	*lstnew(int data, t_stack **stack_a, char **split)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
	{
		if (stack_a)
			lstclear(stack_a, 0);
		print_error(split);
	}
	stack->nbr = data;
	stack->next = NULL;
	stack->index = 0;
	return (stack);
}

void	lstclear(t_stack **stack, int n)
{
	t_stack	*tmp;

	if (!*stack && n)
		exit(0);
	if (lstsize(stack) < 2 && n)
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
