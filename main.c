/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:56:26 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/15 03:02:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_parse_sort(t_data *stack)
{
	if (stack->counter_a == 2)
		ft_sa_sb(stack, 'a');
	if (stack->counter_a == 3)
		ft_three_nb_algo(stack);
	if (stack->counter_a > 3)
		ft_big_nb_algo(stack);
}

char	**ft_cut_arg(char *str)
{
	int		nbword;
	char	**nb;

	nbword = ft_countword(str);
	if (nbword < 1)
		ft_error();
	nb = ft_split(str, ' ');
	return (nb);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_data			*stack;
	char 			**temp;
	int				j;

	if (argc < 2)
		return (ft_printf("./push_swap %s< %sminimum 2 Numbers %s>%s\n",
				RED, END, RED, END));
	if (argc == 2)
		ft_cut_arg(argv[1]);
	stack = ft_calloc(1, sizeof(t_data));
	if (!stack)
		return (0);
	i = 0;
	j = -1;
	while (++i < argc)
	{
		temp = ft_split(argv[i], ' ');
		j = -1;
		if (!temp || !temp[0])
			ft_error();
		while (temp[++j])
		{
			if (!ft_parsing(temp[j]))
				ft_error();
			ft_lstaddback(&stack->stack_a, ft_addstack(ft_atoi2(temp[j])));
			stack->counter_a++;
		}
	}
	ft_checkbefore(stack);
	ft_parse_sort(stack);
	benchtest(1, stack);
}