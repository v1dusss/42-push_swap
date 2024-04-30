/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:40:12 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/30 17:13:10 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char **split)
{
	if (split)
		ft_free_arr((void **)split);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}
