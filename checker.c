/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:08:09 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/28 17:21:28 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_error(t_stack **stack_a, t_stack **stack_b)
{
	lstclear(stack_a);
	lstclear(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	checker_input(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str, "rrr") == 0)
		rrr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rr") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(str, "rb") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(str, "rra") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(str, "sa") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(str, "sb") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pa") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pb") == 0)
		pb(stack_a, stack_b, 0);
	else
		checker_error(stack_a, stack_b);
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

	if (argc == 1)
		return (0);
	loop_checker(&stack_a, &stack_b);
}
