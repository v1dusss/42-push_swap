/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsivanat <vsivanat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 14:09:20 by vsivanat          #+#    #+#             */
/*   Updated: 2024/04/14 14:40:26 by vsivanat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack_a
{
	int				data;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack_a;

typedef struct s_stack_b
{
	int				data;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack_b;

void				push_swap_parse(int argc, char **argv);

#endif