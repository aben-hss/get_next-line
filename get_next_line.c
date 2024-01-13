

#include "get_next_line.h"
#include <libc.h>

char *join_it(char *s1, char *s2)
{
	char *ret;
	if(!s1)
		return(s2);
	ret = (char *) malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
	if(!ret)
		return(NULL);
	strcpy(ret,s1);
	strcat(ret,s2);
	free(s1);
	free(s2);
	return(ret);
}
int check_nl(char *str)
{
	if(!str)
		return(0);
	while(*str)
		if(*(str++) == '\n')
			return(1);
	return(0);
}
char *get_line_s(char *str)
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
	int i = 0;
	while(i < size && str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	if(!*ret)
		return(free(ret),NULL);
	return(ret);
}
char *get_rest(char *str)
{
	int i = 0;
	char *ret;
	if(!str)
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
	free(str);
	if(!*ret)
		return(free(ret),NULL);
	return(ret);
}
char	*get_next_line(int fd)
{
	char *ret;
	static char *rest;
	char *temp;
	ssize_t n;
	if(fd < 0 || BUFFER_SIZE <= 0)
		return(NULL);
	n = 1;
	while(n && !check_nl(rest))
	{
		temp = (char *) malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
		if(!temp)
			return(NULL);
		n  = read(fd,temp,BUFFER_SIZE);
		temp[n] = '\0';
		if(n < 0)
			return(free(temp),free(rest),rest=NULL,NULL);
		rest = join_it(rest,temp);
		if(n < BUFFER_SIZE)
			break;
	}
	ret = get_line_s(rest);
	if(!ret)
		return(free(rest),rest=NULL,NULL);
	rest = get_rest(rest);
	return(ret);
}

// int main()
// {
// 	int fd = open("test.txt",O_RDONLY);
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// }


