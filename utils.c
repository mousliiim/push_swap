/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 02:38:15 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/16 01:17:25 by mmourdal         ###   ########.fr       */
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
		ft_error();
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + *nptr - '0';
		if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
			ft_error();
		nptr++;
	}
	if (ft_isdigit(*nptr))
		ft_error();
	return (result * sign);
}

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
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
				small = curr -> next -> number;
				little = curr -> next;
			}
		}
		curr = curr->next;
	}
	return (little);
}

/*\*/
void	benchtest(int onoff, t_data *stack)
{
	if (onoff == 1)
	{
		ft_printf("\n\t%s   ********************%s\n", GREEN, END);
		ft_printf("\t   %s*%s BENCHTEST [ %sON%s ] %s*%s",
			GREEN, END, GREEN, END, GREEN, END);
		ft_printf("\n\t%s   ********************%s\n", GREEN, END);
		if (stack->stack_a)
			ft_printf("\n\t  Nb count STACK A = [%d]\n", stack->counter_a);
		if (stack->stack_b)
			ft_printf("\n\t  Nb count STACK B = [%d]\n", stack->counter_b);
		ft_printf("\n   ******************************************\n");
		if (stack->stack_a)
			display_lst(stack->stack_a, 'A');
		else
			ft_printf("\t\t%sSTACK A IS EMPTY !%s\n", RED, END);
		if (stack->stack_b)
			display_lst(stack->stack_b, 'B');
		else
			ft_printf("\t     %sSTACK B IS EMPTY !%s\n", RED, END);
	}
	if (onoff == 0)
		ft_printf("\t     %s*%s BENCHTEST [ %sOFF%s ] %s*%s",
			RED, END, RED, END, RED, END);
}
/**/