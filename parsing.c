/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:59:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/12 02:57:18 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sort(t_stack *lst)
{
	t_stack	*begin;
	t_stack	*size;
	int		i;
	int		lstsize;

	lstsize = 0;
	size = lst;
	while (size)
	{
			lstsize++;
			size = size->next;
	}
	i = 0;
	while (i < lstsize)
	{
		begin = lst;
		while (begin->next != NULL)
		{
			if (begin->number > begin->next->number)
				return (1);
			begin = begin->next;
		}
		i++;
	}
	return (0);
}

int	ft_parsing(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_checkdouble(t_stack *lst)
{
	t_stack	*begin;
	t_stack	*cmp;

	begin = lst;
	while (begin)
	{
		cmp = begin->next;
		while (cmp)
		{
			if (begin->number == cmp->number)
				ft_error();
			cmp = cmp->next;
		}
		begin = begin->next;
	}
	return (1);
}

void	ft_checkbefore(t_data *stack)
{
	ft_checkdouble(stack->stack_a);
	if (!ft_already_sort(stack->stack_a))
		exit(0);
}