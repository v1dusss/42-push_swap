/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:08:09 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/28 17:36:31 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_output(t_stack **stack_a, t_stack **stack_b, int output)
{
	if (*stack_a)
		lstclear(stack_a);
	if (*stack_b)
		lstclear(stack_b);
	if (output)
	{
		if (output == 1)
			ft_putstr_fd("Error\n", 2);
		else
			ft_putstr_fd("KO\n", 1);
		exit(1);
	}
	else
	{
		ft_putstr_fd("OK\n", 1);
		exit(0);
	}
}

void	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
		checker_output(stack_a, stack_b, 2);
	temp = lstfirst(stack_a);
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
		{
			checker_output(stack_a, stack_b, 2);
		}
		temp = temp->next;
	}
	checker_output(stack_a, stack_b, 0);
}

void	checker_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(stack_a, 0);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(stack_b, 0);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(stack_a, 0);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(stack_b, 0);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rra(stack_a, 0);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrb(stack_b, 0);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		checker_output(stack_a, stack_b, 1);
}

void	loop_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
		{
			break ;
		}
		checker_input(str, stack_a, stack_b);
		free(str);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	push_swap_parse(argc, argv, &stack_a);
	loop_checker(&stack_a, &stack_b);
	is_sorted(&stack_a, &stack_b);
}
