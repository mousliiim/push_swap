/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_best_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:36:18 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/03 02:54:55 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_best_is_rr_or_rrr(t_data *stack, int choice, int i, int j)
{
	if ((stack->move->tabmouv[i] && stack->move->tabmouv[j]) && choice == 1)
		ft_rra_rrb(stack, '2');
	if ((stack->move->tabmouv[i] && stack->move->tabmouv[j]) && choice == 2)
		ft_ra_rb(stack, '2');
	if (stack->move->tabmouv[i])
		stack->move->tabmouv[i]--;
	if (!stack->move->tabmouv[i])
		stack->move->booll[i] = 0;
	if (stack->move->tabmouv[j])
		stack->move->tabmouv[j]--;
	if (!stack->move->tabmouv[j])
		stack->move->booll[j] = 0;
}

void	ft_best_is_ra_or_rb(t_data *stack)
{
	if (stack->move->booll[0])
	{
		if (stack->move->tabmouv[0])
		{
			ft_ra_rb(stack, 'a');
			stack->move->tabmouv[0]--;
		}
		if (!stack->move->tabmouv[0])
			stack->move->booll[0] = 0;
	}
	if (stack->move->booll[2])
	{
		if (stack->move->tabmouv[2])
		{
			ft_ra_rb(stack, 'b');
			stack->move->tabmouv[2]--;
		}
		if (!stack->move->tabmouv[2])
			stack->move->booll[2] = 0;
	}
}

void	ft_best_is_rra_or_rrb(t_data *stack)
{
	if (stack->move->booll[1])
	{
		if (stack->move->tabmouv[1])
		{
			ft_rra_rrb(stack, 'a');
			stack->move->tabmouv[1]--;
		}
		if (!stack->move->tabmouv[1])
			stack->move->booll[1] = 0;
	}
	if (stack->move->booll[3])
	{
		if (stack->move->tabmouv[3])
		{
			ft_rra_rrb(stack, 'b');
			stack->move->tabmouv[3]--;
		}
		if (!stack->move->tabmouv[3])
			stack->move->booll[3] = 0;
	}
}

static int	ft_nb_superior_inc(t_stack *curr_a, t_stack *node, long supbound)
{
	if (!curr_a || !node)
		ft_error(1);
	while (curr_a)
	{
		if (curr_a->number > node->number)
		{
			supbound = curr_a->number;
			break ;
		}
		curr_a = curr_a->next;
	}
	return (supbound);
}

long	ft_nb_superior_bound(t_stack *node, t_data *stack)
{
	static t_stack	*curr_a = NULL;
	long			supbound;

	supbound = 2147483646;
	curr_a = stack->stack_a;
	supbound = ft_nb_superior_inc(curr_a, node, supbound);
	curr_a = stack->stack_a;
	while (curr_a)
	{
		if (curr_a->number > node->number && curr_a->number < supbound)
			supbound = curr_a->number;
		curr_a = curr_a->next;
	}
	if (supbound == 2147483646)
	{
		curr_a = find_small_nb(stack);
		supbound = curr_a->number;
	}
	return (supbound);
}
