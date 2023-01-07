/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/07 23:44:07 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*ft_addstack(int nb)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	ptr->number = nb;
	ptr->next = NULL;
	return (ptr);
}

void	display_lst(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = lst;
	ft_printf("\n   ****** DISPLAY CONTENT LINKED LIST *****\n\n");
	while (temp != NULL)
	{
		++i;
		printf("\t Contenu du noeud [%d] : %d\n", i, temp->number);
		temp = temp->next;
	}
	ft_printf("\n   ****************************************\n");
}

t_stack	*ft_lstlaste(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (*lst)
	{
		last = ft_lstlaste(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

void ft_error(void)
{
	ft_printf("Error\n");
	exit(1);
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

int	main(int argc, char *argv[])
{
	int				i;
	static t_stack	*tab = NULL;

	if (argc == 1)
		return (ft_printf("./push_swap %s< %sNumbers%s >%s\n",
				RED, END, RED, END));
	tab = malloc(sizeof(t_stack));
	if (!tab)
		return (0);
	tab->number = ft_atoi(argv[1]);
	i = 2;
	while (argv[i])
	{
		if (!ft_parsing(argv[i]) || !ft_parsing(argv[1]))
			ft_error();
		ft_lstaddback(&tab, ft_addstack(ft_atoi(argv[i])));
		i++;
	}
	ft_checkdouble(tab);
	display_lst(tab);
}