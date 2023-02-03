/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_third.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 05:03:05 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/03 03:27:46 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(t_stack *stack_a)
{
	t_stack	*tmpnext;
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp != NULL)
	{
		tmpnext = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmpnext;
	}
	free(tmp);
	tmp = NULL;
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_free_error(t_data *stack, char **temp)
{
	ft_free(stack->stack_a);
	ft_free_split(temp);
	free(stack);
	ft_error(0);
}

void	ft_free_error2(t_data *stack, int *array_lis, int *array_lis2)
{
	ft_free(stack->stack_a);
	free(array_lis2);
	free(array_lis);
	free(stack);
	ft_error(1);
}

void	ft_free_error_3(t_data *stack)
{
	ft_free(stack->stack_a);
	ft_free(stack->stack_b);
	free(stack);
	ft_error(1);
}
