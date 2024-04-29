/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:21:44 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/29 21:18:08 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_atoi(t_stack **stack_a, const char *str, char **split)
{
	int		i;
	int		a;
	long	k;

	i = 0;
	a = 1;
	k = 0;
	if (str[i] == '-')
		a = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k = k * 10 + (str[i++] - '0');
		if ((k * a) > 2147483647 || (k * a) < -2147483648)
			break ;
		if (!str[i])
			return (k * a);
	}
	if (lstsize(stack_a) > 0)
		lstclear(stack_a, 0);
	print_error(split);
	return (0);
}

void	double_input_check(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	temp = lstfirst(stack_a);
	while (temp)
	{
		a = temp->next;
		while (a)
		{
			if (temp->nbr == a->nbr)
			{
				lstclear(stack_a, 0);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			a = a->next;
		}
		temp = temp->next;
	}
}

void	allready_sorted(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*a;

	temp = lstfirst(stack_a);
	while (temp)
	{
		a = temp->next;
		if (a && temp->nbr > a->nbr)
			return ;
		temp = temp->next;
	}
	lstclear(stack_a, 0);
	exit(0);
}

void	loop_parse(t_stack **stack_a, char **split, int j, int nbr)
{
	static int	x;
	t_stack		*old;
	t_stack		*new;

	old = NULL;
	new = NULL;
	while (split[++j])
	{
		nbr = push_swap_atoi(stack_a, split[j], split);
		new = lstnew(nbr, stack_a, split);
		if (x++ == 0)
		{
			*stack_a = new;
			new->prev = NULL;
		}
		else
		{
			old = lstlast(stack_a);
			old->next = new;
			new->prev = old;
		}
		old = new;
	}
}

void	push_swap_parse(int argc, char **argv, t_stack **stack_a)
{
	int		i;
	int		j;
	int		nbr;
	char	**split;

	i = 0;
	nbr = 0;
	j = 0;
	while (++i < argc)
	{
		j = -1;
		split = ft_split(argv[i], ' ');
		if (!split)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		if (!split[0])
			print_error(split);
		loop_parse(stack_a, split, j, nbr);
		ft_free_arr((void **)split);
	}
	if (!*stack_a || lstsize(stack_a) < 2)
		lstclear(stack_a, 1);
	double_input_check(stack_a);
	allready_sorted(stack_a);
}
