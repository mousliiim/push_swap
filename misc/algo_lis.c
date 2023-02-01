/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:35:55 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/01 17:14:18 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*ft_fill_lis2(t_data *stack, int *array_lis, int *array_lis2)
{
	int	i;
	int	j;

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
	return (array_lis2);
}

static int	ft_size_lis(int *array_lis2, t_data *stack)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while (i < stack->counter_a)
	{
		if (array_lis2[i] == count)
			count++;
		i++;
	}
	return (count);
}

static int	*ft_lis(int *array_lis, int *array_lis2, t_data *stack)
{
	int		*tab;
	int		i;
	int		count;
	int		index;

	array_lis2 = ft_fill_lis2(stack, array_lis, array_lis2);
	count = ft_size_lis(array_lis2, stack);
	tab = malloc(sizeof(int) * count);
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

static void	ft_sort_lis(t_data *stack, int *lis_tab)
{
	t_stack	*curr;

	while (stack->counter_a != stack->lis_count - 1)
	{
		curr = stack->stack_a;
		if (ft_verif(curr->number, lis_tab, stack->lis_count - 1))
			ft_ra_rb(stack, 'a');
		else
			ft_push_stack(stack, 'b');
	}
}

void	ft_init_lis(t_data *stack)
{
	t_stack	*curr;
	int		i;
	int		*array_lis;
	int		*array_lis2;
	int		*lis_tab;

	array_lis = malloc(sizeof(int) * stack->counter_a);
	if (!array_lis)
		ft_error(1);
	array_lis2 = malloc(sizeof(int) * stack->counter_a);
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
	ft_sort_lis(stack, lis_tab);
	free(array_lis);
	free(array_lis2);
	free(lis_tab);
}
