/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:55:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/31 06:37:18 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lis(int array_lis[], int array_lis2[], t_data *stack)
{
	int		*tab;
	int		i;
	int		j;
	int		count;
	int		index;

	i = 1;
	while (i < stack->counter_a)
	{
		j = 0;
		while (j < i)
		{
			if (array_lis[i] > array_lis[j] && (array_lis2[i] == array_lis2[j]))
				array_lis2[i] += 1;
			j++;
		}
		i++;
	}
	i = 0;
	count = 1;
	while (i < stack->counter_a)
	{
		if (array_lis2[i] == count)
			count++;
		i++;
	}
	tab = ft_calloc(count, sizeof(int));
	if (!tab)
		ft_error(1);
	stack->lis_count = count;
	index = count - 2;
	i = stack->counter_a;
	while (i--)
	{
		if (array_lis2[i] == count - 1)
		{
			tab[index] = array_lis[i];
			index--;
			count--;
		}
	}
	return (tab);
}

long	ft_nb_superior_bound(t_stack *node, t_data *stack)
{
	static t_stack	*curr_a = NULL;
	long			supbound;

	supbound = 2147483646;
	curr_a = stack->stack_a;
	while (curr_a)
	{
		if (curr_a->number > node->number)
		{
			supbound = curr_a->number;
			break ;
		}
		curr_a = curr_a->next;
	}
	curr_a = stack->stack_a;
	while (curr_a)
	{
		if (curr_a->number > node->number && curr_a->number < supbound)
			supbound = curr_a->number;
		curr_a = curr_a->next;
	}
	if (supbound == 2147483646)
	{
		curr_a = find_small_nb(stack);
		supbound = curr_a->number;
	}
	return (supbound);
}

void	ft_countdatamove(t_data *stack, int *tab)
{
	int			move[4];
	int			i;
	int			j;
	int			cmp[2];
	static int	count = 0;

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
	i = 0;
	count++;
	while (i < 4)
	{
		if (ft_findsmalltab(move) == ft_findsmalltab(stack->move->tab))
		{
			j = 0;
			while (j < 4)
			{
				cmp[0] += move[j];
				cmp[1] += stack->move->tab[j];
			j++;
			}
			if (cmp[0] < cmp[1])
				j = 1;
			else
				j = 0;
		}
		if (ft_findsmalltab(move) < ft_findsmalltab(stack->move->tab)
			|| count == 1 || j == 1)
		{
			j = 0;
			while (j < 4)
			{
				stack->move->tabmouv[j] = tab[j];
			j++;
			}
			j = 0;
			while (j < 4)
			{
				stack->move->tab[j] = move[j];
			j++;
			}
		}
		i++;
	}
	if (count == stack->counter_b)
	{
		count = 0;
		if (stack->move->tab[0] <= stack->move->tab[1]
			&& stack->move->tab[0] <= stack->move->tab[2]
			&& stack->move->tab[0] <= stack->move->tab[3])
		{
			if (stack->move->tabmouv[0])
				stack->move->booll[0] = 1;
			if (stack->move->tabmouv[2])
				stack->move->booll[2] = 1;
		}
		else if (stack->move->tab[1] <= stack->move->tab[0]
			&& stack->move->tab[1] <= stack->move->tab[2]
			&& stack->move->tab[1] <= stack->move->tab[3])
		{
			if (stack->move->tabmouv[1])
				stack->move->booll[1] = 1;
			if (stack->move->tabmouv[3])
				stack->move->booll[3] = 1;
		}
		else if (stack->move->tab[3] <= stack->move->tab[2]
			&& stack->move->tab[3] <= stack->move->tab[0]
			&& stack->move->tab[3] <= stack->move->tab[1])
		{
			if (stack->move->tabmouv[1])
				stack->move->booll[1] = 1;
			if (stack->move->tabmouv[2])
				stack->move->booll[2] = 1;
		}
		else if (stack->move->tab[2] <= stack->move->tab[3]
			&& stack->move->tab[2] <= stack->move->tab[0]
			&& stack->move->tab[2] <= stack->move->tab[1])
		{
			if (stack->move->tabmouv[0])
				stack->move->booll[0] = 1;
			if (stack->move->tabmouv[3])
				stack->move->booll[3] = 1;
		}
	}
}

void	ft_optimal_moves_finder(t_data *stack)
{
	t_stack	*curr_b;
	int		index_a;
	int		index_b;
	int		nbsup_b;
	int		tab[4];

	stack->move = ft_calloc(1, sizeof(t_cmove));
	if (!stack->move)
		ft_error(1);
	curr_b = stack->stack_b;
	while (curr_b != NULL)
	{
		nbsup_b = ft_nb_superior_bound(curr_b, stack);
		index_a = ft_find_nb_list_index(stack->stack_a, stack, nbsup_b, 'o');
		index_b = ft_find_nb_list_index(stack->stack_b,
				stack, curr_b->number, 'o');
		tab[0] = index_a;
		tab[1] = ft_find_nb_list_index(stack->stack_a, stack, nbsup_b, 'a');
		tab[2] = index_b;
		tab[3] = ft_find_nb_list_index(stack->stack_b,
				stack, curr_b->number, 'r');
		ft_countdatamove(stack, tab);
	curr_b = curr_b->next;
	}
}

void	ft_bestmove(t_data *stack)
{
	while (stack->move->booll[0] || stack->move->booll[1]
		|| stack->move->booll[2] || stack->move->booll[3])
	{
		if ((stack->move->booll[0] && stack->move->booll[2]))
		{
			if (stack->move->tabmouv[0] && stack->move->tabmouv[2])
				ft_ra_rb(stack, '2');
			if (stack->move->tabmouv[0])
				stack->move->tabmouv[0]--;
			if (!stack->move->tabmouv[0])
				stack->move->booll[0] = 0;
			if (stack->move->tabmouv[2])
				stack->move->tabmouv[2]--;
			if (!stack->move->tabmouv[2])
				stack->move->booll[2] = 0;
		}
		else if (stack->move->booll[0] || stack->move->booll[2])
		{
			if (stack->move->booll[0])
			{
				if (stack->move->tabmouv[0])
				{
					ft_ra_rb(stack, 'a');
					stack->move->tabmouv[0]--;
				}
				if (!stack->move->tabmouv[0])
					stack->move->booll[0] = 0;
			}
			if (stack->move->booll[2])
			{
				if (stack->move->tabmouv[2])
				{
					ft_ra_rb(stack, 'b');
					stack->move->tabmouv[2]--;
				}
				if (!stack->move->tabmouv[2])
					stack->move->booll[2] = 0;
			}
		}
		if ((stack->move->booll[1] && stack->move->booll[3]))
		{
			if (stack->move->tabmouv[1] && stack->move->tabmouv[3])
				ft_rra_rrb(stack, '2');
			if (stack->move->tabmouv[1])
				stack->move->tabmouv[1]--;
			if (!stack->move->tabmouv[1])
				stack->move->booll[1] = 0;
			if (stack->move->tabmouv[3])
				stack->move->tabmouv[3]--;
			if (!stack->move->tabmouv[3])
				stack->move->booll[3] = 0;
		}
		else if ((stack->move->booll[1] && stack->move->tabmouv[1])
			|| (stack->move->booll[3] && stack->move->tabmouv[3]))
		{
			if (stack->move->booll[1])
			{
				if (stack->move->tabmouv[1])
				{
					ft_rra_rrb(stack, 'a');
					stack->move->tabmouv[1]--;
				}
				if (!stack->move->tabmouv[1])
					stack->move->booll[1] = 0;
			}
			if (stack->move->booll[3])
			{
				if (stack->move->tabmouv[3])
				{
					ft_rra_rrb(stack, 'b');
					stack->move->tabmouv[3]--;
				}
				if (!stack->move->tabmouv[3])
					stack->move->booll[3] = 0;
			}
		}
	}
	ft_push_stack(stack, 'a');
}

void	ft_big_nb_algo(t_data *stack, int i)
{
	t_stack		*curr;
	int			*lis_tab;
	int			*array_lis;
	int			*array_lis2;
	t_stack		*smallnb;

	array_lis = malloc(sizeof(int) * stack->counter_a + 1);
	if (!array_lis)
		ft_error(1);
	array_lis2 = malloc(sizeof(int) * stack->counter_a + 1);
	if (!array_lis2)
		ft_error(1);
	curr = stack->stack_a;
	i = -1;
	while (curr != NULL)
	{
		array_lis[++i] = curr->number;
		array_lis2[i] = 1;
		curr = curr->next;
	}
	lis_tab = ft_lis(array_lis, array_lis2, stack);
	while (stack->counter_a != stack->lis_count - 1)
	{
		curr = stack->stack_a;
		if (ft_verif(curr->number, lis_tab, stack->lis_count - 1))
			ft_ra_rb(stack, 'a');
		else
			ft_push_stack(stack, 'b');
	}
	smallnb = find_small_nb(stack);
	i = ft_find_nb_list_index(stack->stack_a, stack, smallnb->number, 'o');
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		if (i <= (stack->counter_a / 2))
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
	while (stack->counter_b != 0)
	{
		ft_optimal_moves_finder(stack);
		ft_bestmove(stack);
	}
	smallnb = find_small_nb(stack);
	i = ft_find_nb_list_index(stack->stack_a, stack, smallnb->number, 'o');
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		if (i <= (stack->counter_a / 2))
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
}