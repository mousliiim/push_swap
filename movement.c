/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:42:14 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/13 03:07:44 by mmourdal         ###   ########.fr       */
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
		if (c == '2')
		{
			ft_sa_sb(stack, 'a');
			ft_sa_sb(stack, 'b');
		}
	}
}

static void	ft_rotate_rarb(t_data *stack, t_stack *last, char c, int temp)
{
	if (c == 'a')
	{
		if (!stack)
			exit(0);
		temp = stack->stack_a->number;
		last = ft_lstlaste(stack->stack_a);
		stack->stack_a = stack->stack_a->next;
		last->next = ft_addstack(temp);
	}
	if (c == 'b')
	{
		if (!stack)
			exit(0);
		temp = stack->stack_b->number;
		last = ft_lstlaste(stack->stack_b);
		stack->stack_b = stack->stack_b->next;
		last->next = ft_addstack(temp);
	}
}

void	ft_ra_rb(t_data *stack, char c)
{
	static int		temp = 0;
	static t_stack	*last = NULL;

	if (stack)
	{
		if (c == 'a')
		{
			ft_rotate_rarb(stack, last, 'a', temp);
			ft_printf("ra\n");
		}
		if (c == 'b')
		{
			ft_rotate_rarb(stack, last, 'b', temp);
			ft_printf("rb\n");
		}
		if (c == '2')
		{
			ft_ra_rb(stack, 'a');
			ft_ra_rb(stack, 'b');
		}
	}
}

void	rotate_rrb_rra(t_data *stack, t_stack *last, t_stack *head, char c)
{
	static t_stack	*beforelast = NULL;
	static t_stack	*tmp = NULL;

	if (c == 'a')
	{
		head = stack->stack_a;
		last = ft_lstlaste(stack->stack_a);
		tmp = stack->stack_a;
		tmp = ft_find_beforelast(tmp);
		stack->stack_a = last;
		stack->stack_a->next = head;
		beforelast = tmp;
		beforelast->next = NULL;
	}
	if (c == 'b')
	{
		head = stack->stack_b;
		last = ft_lstlaste(stack->stack_b);
		tmp = stack->stack_b;
		tmp = ft_find_beforelast(tmp);
		stack->stack_b = last;
		stack->stack_b->next = head;
		beforelast = tmp;
		beforelast->next = NULL;
	}
}

void	ft_rra_rrb(t_data *stack, char c)
{
	static t_stack	*head = NULL;
	static t_stack	*last = NULL;

	if (stack)
	{
		if (c == 'a')
		{
			rotate_rrb_rra(stack, last, head, 'a');
			ft_printf("rra\n");
		}
		if (c == 'b')
		{
			rotate_rrb_rra(stack, last, head, 'b');
			ft_printf("rrb\n");
		}
		if (c == '2')
		{
			ft_rra_rrb(stack, 'a');
			ft_rra_rrb(stack, 'b');
		}
	}
	else
		exit(1);
}
