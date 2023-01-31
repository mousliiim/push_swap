/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:30:40 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/31 06:40:11 by mmourdal         ###   ########.fr       */
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

void	ft_pushmin(t_data *stack)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;
	int				index;

	curr = stack->stack_a;
	small = find_small_nb(stack);
	index = ft_find_nb_list_index(stack->stack_a, stack, small->number, 'o');
	while (stack->stack_a->number != small->number)
	{
		if (index <= stack->counter_a / 2)
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
	ft_push_stack(stack, 'b');
}

void	ft_three_nb_algo_movement(t_data *stack, t_stack *small)
{
	if (!stack)
		ft_error(1);
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
