/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 10:21:44 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/14 14:31:49 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_parse(int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		while (split[j])
		{
			printf("%s\n", split[j]);
			j++;
		}
		i++;
	}
}
