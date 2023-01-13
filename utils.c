/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:38:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/13 03:07:07 by mmourdal         ###   ########.fr       */
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
	if (*nptr == '-' || *nptr == '+')
		ft_error();
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_error();
		nptr++;
	}
	return (result * sign);
}

void	ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
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
		printf("\t Contenu du noeud [%d] : %d\n", i, temp->number);
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

t_stack	*ft_find_beforelast(t_stack *tmp)
{
	while (tmp->next->next != NULL)
			tmp = tmp->next;
	return (tmp);
}