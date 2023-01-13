/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:42:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/13 21:31:38 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sb(t_data *stack, char c)
{
	int	temp;

	if (stack)
	{
		if (c == 'a' && stack->stack_a)
		{
			temp = stack->stack_a->number;
			stack->stack_a->number = stack->stack_a->next->number;
			stack->stack_a->next->number = temp;
			ft_printf("sa\n");
		}
		if (c == 'b' && stack->stack_b)
		{
			temp = stack->stack_b->number;
			stack->stack_b->number = stack->stack_b->next->number;
			stack->stack_b->next->number = temp;
			ft_printf("sb\n");
		}
		if (c == '2' && (stack->stack_a && stack->stack_b))
		{
			ft_sa_sb(stack, 'a');
			ft_sa_sb(stack, 'b');
		}
	}
}

void	ft_ra_rb(t_data *stack, char c)
{
	static int		temp = 0;
	static t_stack	*last = NULL;

	if (stack)
	{
		if (c == 'a' && stack->stack_a)
		{
			ft_rotate_ra_rb(stack, last, 'a', temp);
			ft_printf("ra\n");
		}
		if (c == 'b' && stack->stack_b)
		{
			ft_rotate_ra_rb(stack, last, 'b', temp);
			ft_printf("rb\n");
		}
		if (c == '2' && (stack->stack_a && stack->stack_b))
		{
			ft_ra_rb(stack, 'a');
			ft_ra_rb(stack, 'b');
		}
	}
}

void	ft_rra_rrb(t_data *stack, char c)
{
	static t_stack	*head = NULL;
	static t_stack	*last = NULL;

	if (stack)
	{
		if (c == 'a' && stack->stack_a)
		{
			ft_rotate_rrb_rra(stack, last, head, 'a');
			ft_printf("rra\n");
		}
		if (c == 'b' && stack->stack_b)
		{
			ft_rotate_rrb_rra(stack, last, head, 'b');
			ft_printf("rrb\n");
		}
		if (c == '2' && (stack->stack_a && stack->stack_b))
		{
			ft_rra_rrb(stack, 'a');
			ft_rra_rrb(stack, 'b');
		}
	}
}

void	ft_push_stack(t_data *stack, char c)
{
	static t_stack	*tmp = NULL;
	static t_stack	*prev = NULL;

	if (stack)
	{
		if (c == 'a' && stack->stack_b)
		{
			tmp = stack->stack_b;
			stack->stack_b = stack->stack_b->next;
			prev = stack->stack_a;
			stack->stack_a = tmp;
			stack->stack_a->next = prev;
			ft_printf("pa\n");
		}
		if (c == 'b' && stack->stack_a)
		{
			tmp = stack->stack_a;
			stack->stack_a = stack->stack_a->next;
			prev = stack->stack_b;
			stack->stack_b = tmp;
			stack->stack_b->next = prev;
			ft_printf("pb\n");
		}
	}
}