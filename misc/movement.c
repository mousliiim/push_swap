/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:42:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/03 02:53:58 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_ss(t_data *stack)
{
	int	temp;

	temp = stack->stack_a->number;
	stack->stack_a->number = stack->stack_a->next->number;
	stack->stack_a->next->number = temp;
	temp = stack->stack_b->number;
	stack->stack_b->number = stack->stack_b->next->number;
	stack->stack_b->next->number = temp;
	ft_printf("ss\n");
}

void	ft_sa_sb(t_data *stack, char c)
{
	int	temp;

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
		ft_ss(stack);
}

void	ft_ra_rb(t_data *stack, char c)
{
	static t_stack	*last = NULL;
	static t_stack	*head = NULL;

	if (c == 'a' && stack->stack_a)
	{
		ft_rotate_ra_rb(stack, last, head, 'a');
		ft_printf("ra\n");
	}
	if (c == 'b' && stack->stack_b)
	{
		ft_rotate_ra_rb(stack, last, head, 'b');
		ft_printf("rb\n");
	}
	if (c == '2' && (stack->stack_a && stack->stack_b))
	{
		ft_rotate_ra_rb(stack, last, head, 'a');
		ft_rotate_ra_rb(stack, last, head, 'b');
		ft_printf("rr\n");
	}
}

void	ft_rra_rrb(t_data *stack, char c)
{
	static t_stack	*last = NULL;

	if (c == 'a' && stack->stack_a)
	{
		ft_rotate_rrb_rra(stack, last, 'a');
		ft_printf("rra\n");
	}
	if (c == 'b' && stack->stack_b)
	{
		ft_rotate_rrb_rra(stack, last, 'b');
		ft_printf("rrb\n");
	}
	if (c == '2' && (stack->stack_a && stack->stack_b))
	{
		ft_rotate_rrb_rra(stack, last, 'a');
		ft_rotate_rrb_rra(stack, last, 'b');
		ft_printf("rrr\n");
	}
}

void	ft_push_stack(t_data *stack, char c)
{
	static t_stack	*tmp = NULL;
	static t_stack	*prev = NULL;

	if (c == 'a' && stack->stack_b)
	{
		tmp = stack->stack_b;
		stack->stack_b = stack->stack_b->next;
		prev = stack->stack_a;
		stack->stack_a = tmp;
		stack->stack_a->next = prev;
		ft_increase_decrease_counter(stack, 'a');
		ft_printf("pa\n");
	}
	if (c == 'b' && stack->stack_a)
	{
		tmp = stack->stack_a;
		stack->stack_a = stack->stack_a->next;
		prev = stack->stack_b;
		stack->stack_b = tmp;
		stack->stack_b->next = prev;
		ft_increase_decrease_counter(stack, 'b');
		ft_printf("pb\n");
	}
}
