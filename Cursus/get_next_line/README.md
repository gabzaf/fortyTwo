# get_next_line
Welcome to get_next_line, a project that challenges to create a function that reads a line from a file descriptor. This project is an exercise in file I/O and managing memory dynamically in C programming.

## Table of Contents
1. Introduction
2. Getting Started
3. Function Description
4. Usage
5. Testing

### 1. Introduction
In many programming projects, especially those involving input/output operations, it's often needed to read data from files line by line. 
The get_next_line function should read a line from a file descriptor and return it without the newline character. 
This project will help me understand how to manage buffers, handle file descriptors and allocate memory dynamically in C.

### 2. Getting Started
To get started with get_next_line, clone this repository to your local machine.

Navigate to the get_next_line directory and compile the project using your preferred compiler.

### 3. Function Description
The get_next_line function has the following prototype:

`int get_next_line(int fd, char **line)`

This function reads a line from the file descriptor fd and stores it in the memory pointed to by line. It returns 1 if a line has been read successfully, 0 if the end of the file has been reached, and -1 in case of an error.

### 4.Usage
To use get_next_line in your C programs, include the `get_next_line.h` header file in your source code and link the libft.a library.

### 5.Testing
Testing the implementation is crucial to ensure its correctness and reliability. 

---

Happy coding!
