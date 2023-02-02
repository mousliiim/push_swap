/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_second.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:52:53 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/01 20:41:35 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlaste(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlaste(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

int	ft_find_nb_list_index(t_stack *stack, t_data *info, int nb, char c)
{
	int		index;
	t_stack	*curr;

	curr = stack;
	index = 0;
	while (curr != NULL)
	{
		if (curr->number == nb && c == 'o')
			break ;
		if (curr->number == nb && c == 'a')
			index = 0;
		if (curr->number == nb && c == 'r')
		{
			index = 0;
			if (curr->next == NULL
				&& info->counter_b == 1)
				return (index);
		}
		index++;
		curr = curr->next;
	}
	return (index);
}

void	ft_increase_decrease_counter(t_data *stack, char c)
{
	if (!stack)
		ft_error(1);
	if (c == 'a')
	{
		if (stack->counter_b)
			stack->counter_b--;
		stack->counter_a++;
	}
	if (c == 'b')
	{
		if (stack->counter_a)
			stack->counter_a--;
		stack->counter_b++;
	}
}

void	benchtest(int onoff, t_data *stack)
{
	if (onoff == 1)
	{
		ft_printf("\n\t%s   ********************%s\n", GREEN, END);
		ft_printf("\t   %s*%s BENCHTEST [ %sON%s ] %s*%s",
			GREEN, END, GREEN, END, GREEN, END);
		ft_printf("\n\t%s   ********************%s\n", GREEN, END);
		if (stack->stack_a)
			ft_printf("\n\t  Nb count STACK A = [%d]\n", stack->counter_a);
		if (stack->stack_b)
			ft_printf("\n\t  Nb count STACK B = [%d]\n", stack->counter_b);
		ft_printf("\n   ******************************************\n");
		if (stack->stack_a)
			display_lst(stack->stack_a, 'A');
		else
			ft_printf("\t\t%sSTACK A IS EMPTY !%s\n", RED, END);
		if (stack->stack_b)
			display_lst(stack->stack_b, 'B');
		else
			ft_printf("\t     %sSTACK B IS EMPTY !%s\n", RED, END);
	}
	if (onoff == 0)
		;
}
