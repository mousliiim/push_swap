/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_third_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 05:03:05 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/04 07:01:28 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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

void	ft_free_error2(t_data *stack, char *line)
{
	if (stack->counter_b > 0)
		ft_free(stack->stack_b);
	if (stack->counter_a > 0)
		ft_free(stack->stack_a);
	free(stack);
	free(line);
	ft_error(0);
}

void	ft_free_error_3(t_data *stack)
{
	ft_free(stack->stack_a);
	ft_free(stack->stack_b);
	free(stack);
	ft_error(1);
}
