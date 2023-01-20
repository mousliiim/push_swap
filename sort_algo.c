/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:55:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/20 06:05:37 by mmourdal         ###   ########.fr       */
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
	// i = 0;
	// while (i < stack->counter_a)
	// {
	// 	ft_printf("\nArray for LIS [%d] = %d", i, array_lis[i]);
	// 	ft_printf(" | Array Check LIS [%d] = %d\n", i, array_lis2[i]);
	// 	i++;
	// }
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
		return (0);
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

int	ft_nearest_number(int parent, int enfant)
{
	int			diff;

	diff = 0;
	if (enfant > parent)
		return (-1);
	while (enfant < parent)
	{
		enfant++;
		diff++;
	}
	return (diff);
}

int	ft_nb_superior_bound(t_stack *node, t_data *stack)
{
	static t_stack	*curr_a = NULL;
	int				supbound;

	supbound = 0;
	curr_a = stack->stack_a;
	while (curr_a)
	{
		if (curr_a->number > node->number)
		{
			supbound = curr_a->number;
			break;
		}
		curr_a = curr_a->next;
	}
	curr_a = stack->stack_a;
	while (curr_a)
	{
		if (curr_a->number > node->number && curr_a->number < supbound)
		{
			supbound = curr_a->number;
		}
		curr_a = curr_a->next;
	}
	if (!supbound)
	{
		curr_a = find_small_nb(stack);
		supbound = curr_a->number;
	}
	return (supbound);
}

void	ft_optimal_moves_finder(t_data *stack)
{
	t_stack *head;
	int		nbsup;
	int		index;

	 while (stack->counter_b)
	 {
		head = stack->stack_b;
		nbsup = ft_nb_superior_bound(head, stack);
		index = ft_find_nb_list_index(stack->stack_a, nbsup);
		while (head->number != nbsup)
		{
			head = stack->stack_a;
			if (head->number == nbsup)
				break;
			if (index < (stack->counter_a / 2))
				ft_ra_rb(stack, 'a');
			else
				ft_rra_rrb(stack, 'a');
		}
		if (head->number == nbsup)
		{
			ft_push_stack(stack, 'a');
		}
	}
	while (ft_already_sort(stack->stack_a))
	{
		ft_ra_rb(stack, 'a');
	}
}

void	ft_big_nb_algo(t_data *stack)
{
	t_stack		*curr;
	int			*lis_tab;
	int			*array_lis;
	int			*array_lis2;
	t_stack		*smallnb;
	int			i;

	array_lis = malloc(sizeof(int) * stack->counter_a + 1);
	if (!array_lis)
		ft_error();
	array_lis2 = malloc(sizeof(int) * stack->counter_a + 1);
	if (!array_lis2)
		ft_error();
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
	i = ft_find_nb_list_index(stack->stack_a, smallnb->number);
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		ft_ra_rb(stack, 'a');
	}
	// i = 0;
	// printf("\n\tLIS = ");
	// while (i < stack->lis_count - 1)
	// {
	// 	printf("[%d] ", lis_tab[i]);
	// 	i++;
	// }
	// printf("\n");
	ft_optimal_moves_finder(stack);
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