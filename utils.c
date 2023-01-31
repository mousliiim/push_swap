/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:38:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/31 06:39:23 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*nptr >= 7 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+' || *nptr == ' ' || *nptr == '\0')
		ft_error(0);
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_error(0);
		nptr++;
	}
	if (ft_isdigit(*nptr))
		ft_error(0);
	return (result * sign);
}

void	ft_error(int nb)
{
	if (nb == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (nb == 1)
	{
		ft_putstr_fd("Memory Allocation Failed\n", 2);
		exit(1);
	}
}

void	display_lst(t_stack *lst, char c)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lst;
	ft_printf("\n   ****** DISPLAY CONTENT LINKED LIST %c *****\n\n", c);
	while (temp != NULL)
	{
		++i;
		ft_printf("\t Contenu du noeud [%d] : %d\n", i, temp->number);
		temp = temp->next;
	}
	ft_printf("\n   ******************************************\n");
}

t_stack	*ft_addstack(int nb)
{
	t_stack	*ptr;

	ptr = ft_calloc(1, sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->number = nb;
	ptr->next = NULL;
	return (ptr);
}

t_stack	*find_small_nb(t_data *stack)
{
	static t_stack	*curr = NULL;
	static t_stack	*little = NULL;
	int				small;

	curr = stack->stack_a;
	little = curr;
	small = curr -> number;
	while (curr != NULL)
	{
		if (curr->next != NULL)
		{
			if (small > curr->next->number)
			{
				small = curr->next->number;
				little = curr->next;
			}
		}
		curr = curr->next;
	}
	return (little);
}
