/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/01 16:19:37 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_three_nb_algo(t_data *stack, int i)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;

	if (!stack)
		ft_error(0);
	i = 1;
	small = find_small_nb(stack);
	curr = stack->stack_a;
	while (curr != NULL)
	{
		if (i == 2 && curr->number == small->number
			&& stack->stack_a->number > stack->stack_a->next->next->number)
			ft_ra_rb(stack, 'a');
		if (i == 1 && curr->number == small->number)
		{
			ft_sa_sb(stack, 'a');
			ft_ra_rb(stack, 'a');
		}
		if (i == 3 && curr->number == small->number
			&& stack->stack_a->number < stack->stack_a->next->number)
			ft_rra_rrb(stack, 'a');
		curr = curr->next;
		i++;
	}
	ft_three_nb_algo_movement(stack, small);
}

static void	ft_five_nb_algo(t_data *stack)
{
	if (stack->counter_a == 5)
		ft_pushmin(stack);
	ft_pushmin(stack);
	if (!ft_already_sort(stack->stack_a))
		ft_three_nb_algo(stack, 1);
	if (stack->counter_b == 2)
		ft_push_stack(stack, 'a');
	ft_push_stack(stack, 'a');
}

static void	ft_parse_sort(t_data *stack)
{
	int	if_need;

	if (!stack)
		ft_error(0);
	if_need = 0;
	if (stack->counter_a == 2)
		ft_sa_sb(stack, 'a');
	if (stack->counter_a == 3)
		ft_three_nb_algo(stack, if_need);
	if (stack->counter_a == 4 || stack->counter_a == 5)
		ft_five_nb_algo(stack);
	if (stack->counter_a > 5)
	{
		ft_init_lis(stack);
		ft_big_nb_algo(stack);
	}
}

static void	init_push_swap(int argc, char **argv, t_data *stack, char **temp)
{
	int				i;
	int				j;

	stack = ft_calloc(1, sizeof(t_data));
	if (!stack)
		ft_error(1);
	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = -1;
		while (temp[++j])
		{
			if (!ft_parsing(temp[j]))
				ft_error(0);
			ft_lstaddback(&stack->stack_a, ft_addstack(ft_atoi2(temp[j])));
			stack->counter_a++;
		}
	}
	ft_checkdouble(stack->stack_a);
	if (ft_already_sort(stack->stack_a))
		exit(0);
	ft_parse_sort(stack);
	benchtest(BENCH, stack);
}

int	main(int argc, char *argv[])
{
	static t_data		*stack = NULL;
	static char			**temp = NULL;

	if (argc > 1)
		init_push_swap(argc, argv, stack, temp);
	else
	{
		ft_printf("\n\t./push_swap %sNumber(s)%s or %s\"Number(s)\"%s\n",
			RED, END, RED, END);
		ft_printf("\n\t    Ex: ./push_swap 15 2 3 9 1\n\
	 Ex: ./push_swap \"19 7 1 19 2 0\"\n\n");
	}
}
