/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:00:29 by mmourdal          #+#    #+#             */
/*   Updated: 2023/01/31 06:39:45 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BENCH
#  define BENCH 0
# endif

# include <fcntl.h>
# include "includes/libft/libft.h"
# include "includes/ft_printf/ft_printf.h"
# define GREEN "\033[0;32m"
# define RED "\033[5;31m"
# define END "\033[0m"
# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}	t_stack;

typedef struct s_cmove
{
	int		c_ra;
	int		c_rb;
	int		c_rra;
	int		c_rrb;
	int		bestmove;
	int		tab[4];
	int		booll[4];
	int		tabmouv[4];
}	t_cmove;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_cmove	*move;
	int		counter_a;
	int		counter_b;
	int		lis_count;
}	t_data;

void	ft_checkbefore(t_data *stack);
/** Vérifie si la pile est déjà triée **/
int		ft_already_sort(t_stack *lst);
/** Vérifie si la pile contient des nombres doubles **/
int		ft_checkdouble(t_stack *lst);
/** Convertit une chaine de caractères en entier **/
int		ft_atoi2(const char *nptr);
/** Affiche une erreur par rapport au int donner en parametre **/
void	ft_error(int nb);
/** Affiche la pile A et/ou B **/
void	display_lst(t_stack *lst, char c);
/** Vérifie la validité de la chaine de caractère entrée par l'utilisateur **/
int		ft_parsing(char *str);
/** Ajoute un nouvel élément à la pile **/
t_stack	*ft_addstack(int nb);
/** Vérifie si la pile est déjà triée **/
int		ft_already_sort(t_stack *lst);
/** Effectue un swap entre les deux premiers éléments de la pile **/
void	ft_sa_sb(t_data *stack, char c);
/** Trouve l’avant-dernier noeud de la pile **/
t_stack	*ft_find_beforelast(t_stack *tmp);
/** Pousse un élément de la pile A vers la pile B ou l'inverse **/
void	ft_push_stack(t_data *stack, char c);
/** Effectue une rotation entre la pile A et la pile B **/
void	ft_ra_rb(t_data *stack, char c);
void	ft_rotate_ra_rb(t_data *stack, t_stack *last, char c, int temp);
/** Effectue une rotation inverse entre la pile A et la pile B **/
void	ft_rra_rrb(t_data *stack, char c);
void	ft_rotate_rrb_rra(t_data *stack, t_stack *last, t_stack *head, char c);
/** Trouve le nombre le plus petit de la pile **/
t_stack	*find_small_nb(t_data *stack);
/** Mouvement pour trier l'algo de trois **/
void	ft_three_nb_algo_movement(t_data *stack, t_stack *small);
/** Algo si la pile est superieur a 5 chiffres **/
void	ft_big_nb_algo(t_data *stack, int i);
/** Trouver le dernier noeud d'une liste **/
t_stack	*ft_lstlaste(t_stack *lst);
/** Ajoute un élément à la fin de la pile **/
void	ft_lstaddback(t_stack **lst, t_stack *new);
/** Trouve l'index d'un nombre dans la pile en avant et en arriere **/
int		ft_find_nb_list_index(t_stack *stack, t_data *info, int nb, char c);
/** Vérifie si un nombre est présent dans un tableau **/
int		ft_verif(int nb, int *lis_tab, int sizelis);
/* Affiche la liste et des informations visuel pour le projet */
void	benchtest(int onoff, t_data *stack);
/* Augmente ou Diminue le Compteur de la pile A ou de la pile B */
void	ft_increase_decrease_counter(t_data *stack, char c);
/* Trouve le plus petit chiffre dans un tableau donner en parametre */
int		ft_findsmalltab(int *tab);
/*-*/
void	ft_pushmin(t_data *stack);
#endif