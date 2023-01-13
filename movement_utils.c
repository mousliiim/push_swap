/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:30:40 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/13 21:33:53 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_ra_rb(t_data *stack, t_stack *last, char c, int temp)
{
	if (c == 'a' && stack->stack_a)
	{
		temp = stack->stack_a->number;
		last = ft_lstlaste(stack->stack_a);
		stack->stack_a = stack->stack_a->next;
		last->next = ft_addstack(temp);
	}
	if (c == 'b' && stack->stack_b)
	{
		temp = stack->stack_b->number;
		last = ft_lstlaste(stack->stack_b);
		stack->stack_b = stack->stack_b->next;
		last->next = ft_addstack(temp);
	}
}

void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, t_stack *head, char c)
{
	static t_stack	*beforelast = NULL;
	static t_stack	*tmp = NULL;

	if (c == 'a' && stack->stack_a)
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
	if (c == 'b' && stack->stack_b)
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

t_stack	*ft_find_beforelast(t_stack *tmp)
{
	while (tmp->next->next != NULL)
			tmp = tmp->next;
	return (tmp);
}
