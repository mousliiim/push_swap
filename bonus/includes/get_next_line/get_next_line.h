/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:44:06 by mmourdal          #+#    #+#             */
/*   Updated: 2023/02/03 06:15:15 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_get_line(char *buffer);
char	*ft_strjoin(char *buffer, char *str);
char	*ft_read_next_buffer(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_read_buffer(int fd, char *buffer);
char	*ft_strchr(char *s, int c);

#endif