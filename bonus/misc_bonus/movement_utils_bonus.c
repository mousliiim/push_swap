/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:30:40 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/04 07:36:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	ft_rotate_ra_rb(t_data *stack, t_stack *last, t_stack *head, char c)
{
	static t_stack	*tmp = NULL;

	if (c == 'a' && stack->stack_a && stack->counter_a > 1)
	{
		head = stack->stack_a;
		last = ft_lstlaste(stack->stack_a);
		tmp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		last->next = head;
		head->next = NULL;
	}
	if (c == 'b' && stack->stack_b && stack->counter_b > 1)
	{
		head = stack->stack_b;
		last = ft_lstlaste(stack->stack_b);
		tmp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		last->next = head;
		head->next = NULL;
	}
}

void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, char c)
{
	static t_stack	*tmp = NULL;

	if (c == 'a' && stack->stack_a && stack->counter_a > 1)
	{
		last = ft_lstlaste(stack->stack_a);
		tmp = stack->stack_a;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = stack->stack_a;
		stack->stack_a = last;
	}
	if (c == 'b' && stack->stack_b && stack->counter_b > 1)
	{
		last = ft_lstlaste(stack->stack_b);
		tmp = stack->stack_b;
		while (tmp->next != last)
			tmp = tmp->next;
		tmp->next = NULL;
		last->next = stack->stack_b;
		stack->stack_b = last;
	}
}
