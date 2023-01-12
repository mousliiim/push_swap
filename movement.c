/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:42:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/12 02:44:37 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_data *stack, char c)
{
	int	temp;

	if (stack)
	{
		if (c == 'a')
		{
			temp = stack->stack_a->number;
			stack->stack_a->number = stack->stack_a->next->number;
			stack->stack_a->next->number = temp;
			ft_printf("sa\n");
		}
		if (c == 'b')
		{
			temp = stack->stack_b->number;
			stack->stack_b->number = stack->stack_b->next->number;
			stack->stack_b->next->number = temp;
			ft_printf("sb\n");
		}
		if (c == 's')
		{
			ft_sa_sb(stack, 'a');
			ft_sa_sb(stack, 'b');
		}
	}
}