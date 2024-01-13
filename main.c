#include <libc.h>
#include "get_next_line.h"

int main(void)
{
	char str[] = "This is a samplestring with a newline character.";

	int fd = open("file.txt", O_CREAT | O_RDWR | O_APPEND);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	// ssize_t data = write(fd, str, ft_strlen(str));
	// if (data < 0)
	// {
	// 	perror("write");
	// 	return (1);
	// }
	lseek(fd, 0, SEEK_SET);

	char *line = get_next_line(fd);
	printf("line: |%s\n", line);

	int new_line_position = get_new_line_pos(str);
	printf("new line position: [%d]\n", new_line_position);

	close(fd);
	return (0);
}

