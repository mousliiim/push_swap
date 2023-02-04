/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 06:42:24 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/04 07:35:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_sort_entry2(char *line, t_data *stack)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ft_ra_rb(stack, 'a');
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_ra_rb(stack, 'b');
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_ra_rb(stack, '2');
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_rra_rrb(stack, 'a');
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_rra_rrb(stack, 'b');
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rra_rrb(stack, '2');
	else if (ft_strcmp(line, "printpile\n") == 0)
		benchtest(1, stack);
	else
		ft_free_error2(stack, line);
}

void	ft_sort_entry(char *line, t_data *stack)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa_sb(stack, 'a');
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sa_sb(stack, 'b');
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_sa_sb(stack, '2');
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push_stack(stack, 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_stack(stack, 'b');
	else if (1)
		ft_sort_entry2(line, stack);
	else
		ft_free_error2(stack, line);
}

static void	init_push_swap(int argc, char **argv, t_data *stack, char **temp)
{
	char	*line;

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
	ft_readline(&line, stack);
	if (ft_already_sort(stack->stack_a) && !stack->stack_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free(stack->stack_a);
	if (stack->stack_b)
		ft_free(stack->stack_b);
	free(stack);
}

int	main(int argc, char **argv)
{
	static t_data		*stack = NULL;
	static char			**temp = NULL;

	if (argc > 1)
		init_push_swap(argc, argv, stack, temp);
}
