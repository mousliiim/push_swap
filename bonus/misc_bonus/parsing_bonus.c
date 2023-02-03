/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 01:59:09 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/03 04:57:49 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_already_sort(t_stack *lst)
{
	t_stack	*begin;
	t_stack	*size;
	int		lstsize;

	lstsize = 0;
	size = lst;
	while (size)
	{
			lstsize++;
			size = size->next;
	}
	while (lstsize--)
	{
		begin = lst;
		while (begin->next != NULL)
		{
			if (begin->number > begin->next->number)
				return (0);
			begin = begin->next;
		}
	}
	return (1);
}

int	ft_parsing(char *str)
{
	int	i;

	i = 0;
	if (!*str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
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
				return (1);
			cmp = cmp->next;
		}
		begin = begin->next;
	}
	return (0);
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
