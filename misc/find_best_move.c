/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:41:24 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/01 17:14:24 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_find_best_data(t_data *stack, int *move, int *tab)
{
	int	j;

	j = -1;
	while (++j < 4)
		stack->move->tabmouv[j] = tab[j];
	j = -1;
	while (++j < 4)
		stack->move->tab[j] = move[j];
}

static void	ft_compare_data_move(int *move, int *tab, t_data *stack, int count)
{
	int			i;
	int			j;
	static int	cmp[2] = {0, 0};

	i = -1;
	j = 0;
	while (++i < 4)
	{
		if (ft_findsmalltab(move) == ft_findsmalltab(stack->move->tab))
		{
			j = -1;
			while (++j < 4)
			{
				cmp[0] += move[j];
				cmp[1] += stack->move->tab[j];
			}
			if (cmp[0] < cmp[1])
				j = 1;
			else
				j = 0;
		}
		if (ft_findsmalltab(move) < ft_findsmalltab(stack->move->tab)
			|| count == 1 || j == 1)
			ft_find_best_data(stack, move, tab);
	}
}

static void	ft_condition_bool(t_data *stack, int i, int j)
{
	if (stack->move->tabmouv[i])
		stack->move->booll[i] = 1;
	if (stack->move->tabmouv[j])
		stack->move->booll[j] = 1;
}

static void	ft_fill_bool_tab(t_data *stack, int *count)
{
	*count = 0;
	if (stack->move->tab[0] <= stack->move->tab[1]
		&& stack->move->tab[0] <= stack->move->tab[2]
		&& stack->move->tab[0] <= stack->move->tab[3])
		ft_condition_bool(stack, 0, 2);
	else if (stack->move->tab[1] <= stack->move->tab[0]
		&& stack->move->tab[1] <= stack->move->tab[2]
		&& stack->move->tab[1] <= stack->move->tab[3])
		ft_condition_bool(stack, 1, 3);
	else if (stack->move->tab[3] <= stack->move->tab[2]
		&& stack->move->tab[3] <= stack->move->tab[0]
		&& stack->move->tab[3] <= stack->move->tab[1])
		ft_condition_bool(stack, 1, 2);
	else if (stack->move->tab[2] <= stack->move->tab[3]
		&& stack->move->tab[2] <= stack->move->tab[0]
		&& stack->move->tab[2] <= stack->move->tab[1])
		ft_condition_bool(stack, 0, 3);
}

void	ft_countdatamove(t_data *stack, int *tab)
{
	int					move[4];
	static int			count = 0;

	if (tab[0] > tab[2])
		move[0] = tab[0];
	else
		move[0] = tab[2];
	if (tab[1] > tab[3])
		move[1] = tab[1];
	else
		move[1] = tab[3];
	move[2] = tab[0] + tab[3];
	move[3] = tab[1] + tab[2];
	count++;
	ft_compare_data_move(move, tab, stack, count);
	if (count == stack->counter_b)
		ft_fill_bool_tab(stack, &count);
}
