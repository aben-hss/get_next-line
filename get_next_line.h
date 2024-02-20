/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-hss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:30:36 by aben-hss          #+#    #+#             */
/*   Updated: 2024/01/14 16:30:38 by aben-hss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <ctype.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_strcat(char *dst, char *src);
size_t	ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
int		contains_new_line(char *str);

#endif
