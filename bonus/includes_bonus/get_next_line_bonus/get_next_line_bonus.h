/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:44:06 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/05 06:48:10 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_get_line(char *buffer);
char	*ft_strjoine(char *buffer, char *str);
char	*ft_read_next_buffer(char *buffer);
size_t	ft_strlene(char *str);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_strchre(char *s, int c);

#endif