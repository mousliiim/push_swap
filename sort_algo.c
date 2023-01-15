/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:55:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/15 02:56:56 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_big_nb_algo(t_data *stack)
{
	while (stack->counter_a > 3)
		ft_push_stack(stack, 'b');
	ft_three_nb_algo(stack);
}

static void	ft_three_nb_algo_movement(t_data *stack, t_stack *small)
{
	if (stack->stack_a->number > stack->stack_a->next->number
		&& stack->stack_a->next->next->number == small->number)
	{
		ft_sa_sb(stack, 'a');
		ft_rra_rrb(stack, 'a');
	}
	if (stack->stack_a->number < stack->stack_a->next->next->number
		&& stack->stack_a->next->number == small->number)
		ft_sa_sb(stack, 'a');
}

void	ft_three_nb_algo(t_data *stack)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;
	int				i;

	i = 1;
	small = find_small_nb(stack);
	curr = stack->stack_a;
	while (curr != NULL)
	{
		if (i == 2 && curr->number == small->number
			&& stack->stack_a->number > stack->stack_a->next->next->number)
			ft_ra_rb(stack, 'a');
		if (i == 1 && curr->number == small->number)
		{
			ft_sa_sb(stack, 'a');
			ft_ra_rb(stack, 'a');
		}
		if (i == 3 && curr->number == small->number
			&& stack->stack_a->number < stack->stack_a->next->number)
			ft_rra_rrb(stack, 'a');
		curr = curr->next;
		i++;
	}
	ft_three_nb_algo_movement(stack, small);
}