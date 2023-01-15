/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:00:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/15 02:58:31 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define END "\033[0m"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		counter_a;
	int		counter_b;
}	t_data;

void	ft_checkbefore(t_data *stack);
int		ft_already_sort(t_stack *lst);
int		ft_checkdouble(t_stack *lst);
int		ft_atoi2(const char *nptr);
void	ft_error(void);
void	display_lst(t_stack *lst, char c);
int		ft_checkdouble(t_stack *lst);
int		ft_parsing(char *str);
t_stack	*ft_addstack(int nb);
int		ft_already_sort(t_stack *lst);
void	ft_sa_sb(t_data *stack, char c);
void	ft_ra_rb(t_data *stack, char c);
t_stack	*ft_lstlaste(t_stack *lst);
void	ft_rra_rrb(t_data *stack, char c);
t_stack	*ft_find_beforelast(t_stack *tmp);
void	ft_push_stack(t_data *stack, char c);
void	ft_rotate_ra_rb(t_data *stack, t_stack *last, char c, int temp);
void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, t_stack *head, char c);
t_stack	*find_small_nb(t_data *stack);
int		ft_countword(char *str);
void	ft_three_nb_algo(t_data *stack);
void	ft_big_nb_algo(t_data *stack);
t_stack	*ft_lstlaste(t_stack *lst);
void	ft_lstaddback(t_stack **lst, t_stack *new);
/* BENCHTEST */
void	benchtest(int onoff, t_data *stack);
#endif