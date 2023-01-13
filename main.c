/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/13 21:33:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_parse_sort(t_data *stack)
{
	if (stack->stack_a->counter == 2)
		ft_sa_sb(stack, 'a');
	if (stack->stack_a->counter == 4)
		printf("4 Numbers !\n");
	if (stack->stack_a->counter == 6)
		printf("6 Numbers !\n");
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
			ft_printf("\n\t  Nb count STACK A = [%d]\n", stack->stack_a->counter);
		if (stack->stack_b)
			ft_printf("\n\t  Nb count STACK B = [%d]\n", stack->stack_b->counter);
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
		ft_printf("\t     %s*%s BENCHTEST [ %sOFF%s ] %s*%s",
			RED, END, RED, END, RED, END);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_data			*stack;

	if (argc < 3)
		return (ft_printf("./push_swap %s< %sminimum 2 Numbers %s>%s\n",
				RED, END, RED, END));
	stack = ft_calloc(1, sizeof(t_data));
	if (!stack)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!ft_parsing(argv[i]))
			ft_error();
		ft_lstaddback(&stack->stack_a, ft_addstack(ft_atoi2(argv[i])));
		stack->stack_a->counter++;
	}
	ft_checkbefore(stack);
	ft_parse_sort(stack);
	benchtest(1, stack);
}