# get_next_line
Welcome to get_next_line, a project that challenges to create a function that reads a line from a file descriptor. This project is an exercise in file I/O and managing memory dynamically in C programming.

### 1. Introduction
In many programming projects, especially those involving input/output operations, it's often needed to read data from files line by line. 
The get_next_line function should read a line from a file descriptor and return it without the newline character. 
This project helped me understand how to manage buffers, handle file descriptors and allocate memory dynamically in C.

### 2. Function Description
The get_next_line function has the following prototype:

`int get_next_line(int fd, char **line)`

This function reads a line from the file descriptor fd and stores it in the memory pointed to by line. It returns 1 if a line has been read successfully, 0 if the end of the file has been reached, and -1 in case of an error.
