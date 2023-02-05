/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/05 05:46:56 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_fill_stack_a(int argc, char **argv, t_data *stack, char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = -1;
		while (temp[++j])
		{
			if (!ft_parsing(temp[j]))
				ft_free_error(stack, temp);
			ft_lstaddback(&stack->stack_a,
				ft_addstack(ft_atoi2(temp[j], stack, temp), stack, temp));
			stack->counter_a++;
		}
		while (j--)
			free(temp[j]);
		free(temp);
	}
}

static void	init_push_swap(int argc, char **argv, t_data *stack, char **temp)
{
	stack = ft_calloc(1, sizeof(t_data));
	if (!stack)
		ft_error(1);
	ft_fill_stack_a(argc, argv, stack, temp);
	if (ft_checkdouble(stack->stack_a))
	{
		ft_free(stack->stack_a);
		free(stack);
		ft_error(0);
	}
	if (ft_already_sort(stack->stack_a))
	{
		ft_free(stack->stack_a);
		free(stack);
		exit(0);
	}
	ft_parse_sort(stack);
	benchtest(BENCH, stack);
	ft_free(stack->stack_a);
	free(stack);
}

int	main(int argc, char *argv[])
{
	static t_data		*stack = NULL;
	static char			**temp = NULL;

	if (argc > 1)
		init_push_swap(argc, argv, stack, temp);
	else
		return (0);
}
