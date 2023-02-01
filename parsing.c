/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:59:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/01 13:49:03 by mmourdal         ###   ########.fr       */
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
				return (0);
			begin = begin->next;
		}
		i++;
	}
	return (1);
}

int	ft_parsing(char *str)
{
	if (!*str)
		return (0);
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
				ft_error(0);
			cmp = cmp->next;
		}
		begin = begin->next;
	}
	return (1);
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

int	ft_findsmalltab(int *tab)
{
	int	small;
	int	i;

	i = 0;
	small = tab[0];
	while (i < 4)
	{
		if (small > tab[i])
			small = tab[i];
		i++;
	}
	return (small);
}
