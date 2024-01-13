
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H



#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#include <stdio.h>
#include <libc.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 40
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
int		get_new_line_pos(const char *str);
size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif
