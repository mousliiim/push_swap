/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 02:55:02 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/22 21:17:38 by mmourdal         ###   ########.fr       */
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
	if (!supbound)
	{
		curr_a = find_small_nb(stack);
		supbound = curr_a->number;
	}
	return (supbound);
}

// Implementer Structure Temporaire de t_data pour trouver le chiffre de la pile B qui fait le moin de coup
// Comparer donc la structure dans temp avec les valeur pour c_ra, c_rb etc avec la structure t_data actuel parcouru
// a l'iteration de la boucle dans la fonction ci dessous et donc a la fin que dans la structure temporaire sa contient
// les meilleur coup a appliquer en premier puis le deuxieme puis le troisieme etc.

int	ft_countdatamove(t_data *stack, int *tab)
{
	int	i;
	int	count;
	int	countstruct;

	i = -1;
	count = 0;
	countstruct = 0;
	countstruct += stack->move->c_ra;
	countstruct += stack->move->c_rra;
	countstruct += stack->move->c_rb;
	countstruct += stack->move->c_rrb;
	// printf("\t");
	while (++i < 4)
	{
		count += tab[i];
		// printf("%d || ", tab[i]);
	}
	// printf("Count = %d\n", count);
	// printf("\n");
	if (countstruct > count)
	{
		stack->move->c_ra = tab[0];
		stack->move->c_rb = tab[2];
		stack->move->c_rra = tab[1];
		stack->move->c_rrb = tab[3];
	}
	// printf("\n\nCountstruct = %d\n\n", countstruct);
	return (0);
}

void	ft_optimal_moves_finder(t_data *stack)
{
	t_stack	*curr_b;
	int		index_a;
	int		index_b;
	int		nbsup_b;
	int		*tab;
	int		i;

	i = 1;
	stack->move = ft_calloc(1, sizeof(t_cmove));
	curr_b = stack->stack_b;
	while (curr_b != NULL)
	{
		tab = malloc(sizeof(int) * 4);
		nbsup_b = ft_nb_superior_bound(curr_b, stack);
		index_a = ft_find_nb_list_index(stack->stack_a, nbsup_b, 'o');
		index_b = ft_find_nb_list_index(stack->stack_b, curr_b->number, 'o');
		// printf("\n\t|| Dad = [ %d ] for Node B (Child) [ %d ] ||\n", nbsup_b, curr_b->number);
		// printf("\t|| Index in List A for %d = [ %d ] ||\n", nbsup_b, index_a);
		if (index_a <= (stack->counter_a / 2))
		{
			tab[0] = index_a;
			// printf("\t|| Need to do %d RA", tab[0]);
		}
		else
		{
			tab[1] = ft_find_nb_list_index(stack->stack_a, nbsup_b, 'r');
			// printf("\t|| Need to do %d RRA", tab[1]);
		}
		if (index_b <= (stack->counter_b / 2))
		{
			tab[2] = index_b;
			// printf("|| Need to do %d RB ||\n", tab[2]);
		}
		else
		{
			tab[3] = ft_find_nb_list_index(stack->stack_b, curr_b->number, 'r');
			// printf("|| Need to do %d RRB ||\n", tab[3]);
		}
		// printf("\n\t[ First Call List Stack MOVCOUNT ]\n");
		// printf("\t\t[ Stack->c_ra = %d ]\n", tab[0]);
		// printf("\t\t[ Stack->c_rra = %d ]\n", tab[1]);
		// printf("\t\t[ Stack->c_rb = %d ]\n", tab[2]);
		// printf("\t\t[ Stack->c_rrb = %d ]\n", tab[3]);
		if (i == 1)
		{
			stack->move->c_ra = tab[0];
			stack->move->c_rb = tab[2];
			stack->move->c_rra = tab[1];
			stack->move->c_rrb = tab[3];
		}
		ft_countdatamove(stack, tab);
		i++;
	curr_b = curr_b->next;
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
	i = ft_find_nb_list_index(stack->stack_a, smallnb->number, 'o');
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		if (i <= (stack->counter_a / 2))
			ft_ra_rb(stack, 'a');
		else
			ft_rra_rrb(stack, 'a');
	}
	i = 0;
	// printf("\n\tLIS = ");
	// while (i < stack->lis_count - 1)
	// {
	// 	printf("[%d] ", lis_tab[i]);
	// 	i++;
	// }
	// printf("\n");
	ft_optimal_moves_finder(stack);
	i = 0;
	int movecra = stack->move->c_ra;
	int movecrra = stack->move->c_rra;
	int movecrb = stack->move->c_rb;
	int movecrrb = stack->move->c_rrb;
	curr = stack->stack_b;
	while(stack->counter_b != 0)
	{
		curr = stack->stack_b;
		ft_optimal_moves_finder(stack);
		movecra = stack->move->c_ra;
		movecrra = stack->move->c_rra;
		movecrb = stack->move->c_rb;
		movecrrb = stack->move->c_rrb;
		while ((movecra || movecrra || movecrb || movecrrb))
		{
		while (movecra)
		{
			ft_ra_rb(stack, 'a');
			i++;
			movecra--;
		}
		while (movecrra)
		{
			ft_rra_rrb(stack, 'a');
			i++;
			movecrra--;
		}
		while (movecrb)
		{
			ft_ra_rb(stack, 'b');
			i++;
			movecrb--;
		}
		while (movecrrb)
		{
			ft_rra_rrb(stack, 'b');
			i++;
			movecrrb--;
		}
	}
	if (!movecrb && !movecrrb)
	{
		ft_push_stack(stack, 'a');
	}
	}
	// printf("\n\ncombien de push a ? = %d\n\n", i);
	// smallnb = find_small_nb(stack);
	// i = ft_find_nb_list_index(stack->stack_a, smallnb->number, 'o');
	curr = stack->stack_a;
	smallnb = find_small_nb(stack);
	while (stack->stack_a->number != smallnb->number)
	{
		curr = stack->stack_a;
		ft_ra_rb(stack, 'a');
	}
	// printf("\n\n\n\n\t   [ Best Move Need to Do First ]\n");
	// printf("\t\t[ Stack->c_ra = %d ]\n", stack->move->c_ra);
	// printf("\t\t[ Stack->c_rra = %d ]\n", stack->move->c_rra);
	// printf("\t\t[ Stack->c_rb = %d ]\n", stack->move->c_rb);
	// printf("\t\t[ Stack->c_rrb = %d ]\n", stack->move->c_rrb);
}

int	ft_find_nb_list_index(t_stack *stack, int nb, char c)
{
	int		index;
	t_stack	*curr;

	curr = stack;
	index = 0;
	while (curr != NULL)
	{
		if (curr->number == nb && c == 'o')
			break ;
		if (curr->number == nb && c == 'r')
			index = 0;
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