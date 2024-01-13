

#include "get_next_line_bonus.h"
#include <libc.h>

void my_free(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

char *join_strings(char *s1, char *s2)
{
	char *ret;
	if(!s1 && s2)
		return(s2);
	if (s1 && !s2)
		return (s1);
	if (!s1 && !s2)
		return (NULL);

	ret = (char *) malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if(!ret)
		return(NULL);
	strcpy(ret,s1);
	strcat(ret,s2);
	my_free(s1);
	my_free(s2);
	return(ret);
}
int contains_new_line(char *str)
{
	if(!str || !(*str))
	{
		my_free(str);
		return(0);
	}
	while(*str)
	{
		if(*str == '\n')
			return(1);
		str++;
	}
	return(0);
}

char *extract_line(char *str)
{
	char *ret;
	int size;
	size = 0;
	if(!str)
		return(NULL);
	while(str[size] && str[size]!= '\n')
		size++;
	if(str[size] == '\n')
		size++;
	ret = malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	int i = 0;
	while(i < size && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if(!*ret)
		return	(my_free(ret), NULL);
	return(ret);
}
char  *extract_rest(char *str)
{
	int i = 0;
	char *ret;
	if(!str || !(*str))
		return(NULL);
	while(str[i] && str[i] != '\n')
		i++;
	if(str[i] == '\n')
		i++;
	ret = malloc(sizeof(char) * strlen(str+i) + 1);
	if(!ret)
		return(NULL);
	int j = 0;
	while(str[i])
		ret[j++] = str[i++];
	ret[j] = '\0';
	my_free(str);
	if(!ret[0])
		return	(my_free(ret), ret = NULL, NULL);
	return(ret);
}
char	*get_next_line(int fd)
{
	char *ret;
	static char *rest[OPEN_MAX];
	char *tmp;
	ssize_t n;

	ret = NULL;
	if(BUFFER_SIZE <= 0 || BUFFER_SIZE > SIZE_T_MAX || read(fd, 0, 0) < 0)
	{
		my_free(ret);
		my_free(rest[fd]);
		return (NULL);
	}
	n = 1;
	while(n && !contains_new_line(rest[fd]))
	{
		tmp = (char *) malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if(!tmp)
		{
			my_free(rest[fd]);
			return (NULL);
		}
		n  = read(fd,tmp,BUFFER_SIZE);

		if(n < 0)
		{
			my_free(tmp);
			my_free(rest[fd]);
			return(NULL);
		}
		tmp[n] = '\0';
		rest[fd] = join_strings(rest[fd],tmp);
		if(n < BUFFER_SIZE)
			break;
	}
	ret = extract_line(rest[fd]);
	if(!ret)
		return(my_free(rest[fd]),rest[fd]=NULL,NULL);
	rest[fd] = extract_rest(rest[fd]);
	return(ret);
}

// int main()
// {
// 	int fd = open("file.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(2));
// 	printf("%s",get_next_line(1));
// 	printf("%s",get_next_line(-1));
// 	printf("%s",get_next_line(0));
// }

// int main(void)
// {
//     int fd = open("example.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }

//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s\n", line);
//         free(line);
//     }

//     close(fd);
//     return 0;
// }

