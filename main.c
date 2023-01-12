/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/12 03:26:28 by mmourdal         ###   ########.fr       */
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
		ft_printf("\n\t%s     ********************%s\n", GREEN, END);
		ft_printf("\t     %s*%s BENCHTEST [ %sON%s ] %s*%s",
			GREEN, END, GREEN, END, GREEN, END);
		ft_printf("\n\t%s     ********************%s\n", GREEN, END);
		ft_printf("\n\t  Number count STACK A = [%d]\n", stack->stack_a->counter);
		ft_printf("\n\t  Number count STACK B = [%d]\n", stack->stack_b->counter);
		ft_printf("\n   ******************************************\n");
		display_lst(stack->stack_a, 'A');
		display_lst(stack->stack_b, 'B');
	}
	if (onoff == 0)
	{
		ft_printf("\n\t%s     *********************%s\n", RED, END);
		ft_printf("\t     %s*%s BENCHTEST [ %sOFF%s ] %s*%s",
			RED, END, RED, END, RED, END);
		ft_printf("\n\t%s     *********************\n\n", RED, END);
	}
}

int	main(int argc, char *argv[])
{
	int				i;
	static t_data	*stack = NULL;

	if (argc < 3)
		return (ft_printf("./push_swap %s< %sminimum 2 Numbers %s>%s\n",
				RED, END, RED, END));
	stack = malloc(sizeof(t_data));
	stack->stack_a = malloc(sizeof(t_stack));
	stack->stack_b = malloc(sizeof(t_stack));
	if (!stack || !stack->stack_a || !stack->stack_b)
		return (0);
	stack->stack_a->number = ft_atoi2(argv[1]);
	stack->stack_a->counter++;
	i = 2;
	while (argv[i])
	{
		if (!ft_parsing(argv[i]) || !ft_parsing(argv[1]))
			ft_error();
		ft_lstaddback(&stack->stack_a, ft_addstack(ft_atoi2(argv[i])));
		stack->stack_a->counter++;
		i++;
	}
	ft_checkbefore(stack);
	ft_parse_sort(stack);
	benchtest(1, stack);
}