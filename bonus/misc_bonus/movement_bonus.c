/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:42:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/04 06:42:08 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	ft_ss(t_data *stack)
{
	int	temp;

	temp = stack->stack_a->number;
	stack->stack_a->number = stack->stack_a->next->number;
	stack->stack_a->next->number = temp;
	temp = stack->stack_b->number;
	stack->stack_b->number = stack->stack_b->next->number;
	stack->stack_b->next->number = temp;
}

void	ft_sa_sb(t_data *stack, char c)
{
	int	temp;

	if (c == 'a' && stack->stack_a && stack->counter_a > 1)
	{
		temp = stack->stack_a->number;
		stack->stack_a->number = stack->stack_a->next->number;
		stack->stack_a->next->number = temp;
	}
	if (c == 'b' && stack->stack_b && stack->counter_b > 1)
	{
		temp = stack->stack_b->number;
		stack->stack_b->number = stack->stack_b->next->number;
		stack->stack_b->next->number = temp;
	}
	if (c == '2' && (stack->stack_a && stack->stack_b) && stack->counter_a > 1
		&& stack->counter_b > 1)
		ft_ss(stack);
}

void	ft_ra_rb(t_data *stack, char c)
{
	static t_stack	*last = NULL;
	static t_stack	*head = NULL;

	if (c == 'a' && stack->stack_a && stack->counter_a > 1)
	{
		ft_rotate_ra_rb(stack, last, head, 'a');
	}
	if (c == 'b' && stack->stack_b && stack->counter_b > 1)
	{
		ft_rotate_ra_rb(stack, last, head, 'b');
	}
	if (c == '2' && (stack->stack_a && stack->stack_b) && stack->counter_a > 1
		&& stack->counter_b > 1)
	{
		ft_rotate_ra_rb(stack, last, head, 'a');
		ft_rotate_ra_rb(stack, last, head, 'b');
	}
}

void	ft_rra_rrb(t_data *stack, char c)
{
	static t_stack	*last = NULL;

	if (c == 'a' && stack->stack_a && stack->counter_a > 1)
		ft_rotate_rrb_rra(stack, last, 'a');
	if (c == 'b' && stack->stack_b && stack->counter_b > 1)
		ft_rotate_rrb_rra(stack, last, 'b');
	if (c == '2' && (stack->stack_a && stack->stack_b) && stack->counter_a > 1
		&& stack->counter_b > 1)
	{
		ft_rotate_rrb_rra(stack, last, 'a');
		ft_rotate_rrb_rra(stack, last, 'b');
	}
}

void	ft_push_stack(t_data *stack, char c)
{
	static t_stack	*tmp = NULL;
	static t_stack	*prev = NULL;

	if (c == 'a' && stack->stack_b && stack->counter_b > 0)
	{
		tmp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		prev = stack->stack_a;
		stack->stack_a = tmp;
		stack->stack_a->next = prev;
		ft_increase_decrease_counter(stack, 'a');
	}
	if (c == 'b' && stack->stack_a && stack->counter_a > 0)
	{
		tmp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		prev = stack->stack_b;
		stack->stack_b = tmp;
		stack->stack_b->next = prev;
		ft_increase_decrease_counter(stack, 'b');
	}
}
