# Get Next Line

## Project Description
Get Next Line is a programming project that involves creating a function which reads a line from a file descriptor. This project is part of the 42 school curriculum and aims to enhance understanding of static variables, file descriptors, and memory management in C.

## Function Prototype
```c
char *get_next_line(int fd);
```

## Parameters
- `fd`: The file descriptor to read from

## Return Value
- Read line: correct behavior
- NULL: there is nothing else to read, or an error occurred

## Key Features
- Reads a line from a given file descriptor
- Works with both files and standard input
- Handles multiple file descriptors simultaneously (bonus part)
- Uses only one static variable (bonus part)

## Files to Submit

### Mandatory Part
- get_next_line.c
- get_next_line_utils.c
- get_next_line.h

### Bonus Part
- get_next_line_bonus.c
- get_next_line_bonus.h
- get_next_line_utils_bonus.c

## Compilation
Compile the project using the following command:
```
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
```
Note: The BUFFER_SIZE can be modified to test different buffer sizes.

## Norms and Requirements
- The project must be written in C and comply with the Norm.
- Functions should not quit unexpectedly (segmentation fault, bus error, double free, etc.).
- All heap allocated memory space must be properly freed. No leaks will be tolerated.
- A Makefile must be submitted with the following rules: $(NAME), all, clean, fclean, and re.
- The libft library is not allowed for this project.
- Global variables are forbidden.
- The use of lseek() is not allowed.

## Bonus Part
The bonus part includes:
1. Developing get_next_line() using only one static variable.
2. Managing multiple file descriptors simultaneously.

Note: The bonus part will only be evaluated if the mandatory part is perfect.

## Testing
It's recommended to create test programs to verify the functionality of your get_next_line function. Consider testing with:
- Different buffer sizes
- Various line sizes
- Different types of file descriptors (not just regular files)

## Additional Notes
- The returned line should include the terminating \n character, except if the end of file was reached and does not end with a \n character.
- The function has undefined behavior if the file pointed to by the file descriptor changed since the last call and read() didn't reach the end of file.
- Reading binary files is considered undefined behavior, but you can implement a logical way to handle this if desired.

Remember to thoroughly test your implementation and ensure it works correctly with various scenarios and edge cases.

## Author
This push_swap project was developed by aben-hss as part of the 42 school curriculum.
