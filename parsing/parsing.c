/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:21:44 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/21 22:17:34 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_error(void)
{
	ft_putstr_fd("Malloc error\n", 2);
	exit(1);
}

void	input_error(void)
{
	ft_putstr_fd("Invalid input error\n", 2);
	exit(1);
}
void	double_input_error(void)
{
	ft_putstr_fd("Double input error\n", 2);
	exit(1);
}

void	double_input_check(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	temp = lstfist(stack_a);
	while (temp)
	{
		a = temp->next;
		while (a)
		{
			if (temp->nbr == a->nbr)
				double_input_error();
			a = a->next;
		}
		temp = temp->next;
	}
}

int	push_swap_atoi(const char *str)
{
	int	i;
	int	a;
	int	k;

	i = 0;
	a = 1;
	k = 0;
	// while (ft_isspace(str[i]))
	// 	i++;
	if (str[i] == '-')
		a = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i++] - '0');
		if (!str[i])
			return (k * a);
	}
	input_error();
	return (0);
}

t_stack	*push_swap_lstnew(int data)
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

void	push_swap_parse(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		j;
	int		nbr;
	int		x;
	char	**split;
	t_stack	*old;
	t_stack	*new;

	old = NULL;
	new = NULL;
	i = 0;
	x = 0;
	nbr = 0;
	if (argc == 1)
		input_error();
	if (argc == 2)
		exit(0);
	while (++i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j])
		{
			nbr = push_swap_atoi(split[j]);
			if (nbr == 0 && split[j][0] != '0')
				input_error();
			new = push_swap_lstnew(nbr);
			if (!new)
				malloc_error();
			if (x++ == 0)
			{
				*stack_a = new;
				new->prev = NULL;
			}
			else
			{
				old->next = new;
				new->prev = old;
			}
			old = new;
		}
	}
	double_input_check(stack_a);
}
