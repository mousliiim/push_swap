/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:55:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/18 04:55:09 by mmourdal         ###   ########.fr       */
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
	while (i < stack->counter_a)
	{
		ft_printf("\nArray for LIS [%d] = %d", i, array_lis[i]);
		ft_printf(" | Array Check LIS [%d] = %d\n", i, array_lis2[i]);
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

int	ft_find_nb_list_index(t_stack *stack, int nb)
{
	int		index;
	t_stack	*curr;

	curr = stack;
	index = 0;
	while (curr != NULL)
	{
		if (curr->number == nb)
			return (index);
		index++;
		curr = curr->next;
	}
	return (index);
}

int	ft_verif(int nb, int *lis_tab, int sizelis)
{
	int	i;

	i = 0;
	while (i < sizelis)
	{
		if (nb == lis_tab[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_big_nb_algo(t_data *stack)
{
	t_stack		*curr;
	int			*lis_tab;
	int			array_lis[stack->counter_a + 1];
	int			array_lis2[stack->counter_a + 1];
	// t_stack		*curr2;
	// int			findnb;
	int			i;

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
		{
			printf("curr number = %d\n", curr->number);
			ft_ra_rb(stack, 'a');
		}
		else
			ft_push_stack(stack, 'b');
	}
	i = 0;
	printf("\n\tLIS = ");
	while (i < stack->lis_count - 1)
	{
		printf("[%d] ", lis_tab[i]);
		i++;
	}
	printf("\n");
}

static void	ft_three_nb_algo_movement(t_data *stack, t_stack *small)
{
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

void	ft_three_nb_algo(t_data *stack)
{
	static t_stack	*small = NULL;
	static t_stack	*curr = NULL;
	int				i;

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