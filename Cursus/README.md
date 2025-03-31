# 📌 Cursus (Core Projects)

This section contains the core projects of the 42 curriculum, designed to develop foundational skills in C programming, algorithms, systems programming, and problem-solving. Below is an overview of each project, highlighting key objectives, technical aspects, and acquired skills.

## 🧩 Projects

### 1. Libft

- Goal: Create a custom C library by reimplementing standard functions (libc) and additional utilities.

- Key Features:

	- Implemented 42+ functions, including ft_strlen, ft_substr, ft_split, and memory management tools.

	- Bonus: Linked list manipulation (ft_lstnew, ft_lstadd_back).

- Skills: Memory management, static libraries, defensive programming.

### 2. ft_printf

- Goal: Recode the printf function, handling various conversions (c, s, p, d, i, u, x, X, %).

- Key Features:

	- Variadic arguments (va_list) and dynamic string formatting.

	- Bonus: Supported flags (-0.# +) and minimum width formatting.

- Skills: Parsing, bit manipulation, edge-case handling.

### 3. get_next_line

- Goal: Read a file line by line using a static variable and dynamic memory allocation.

- Key Features:

	- Single static variable implementation.

	- Bonus: Multi-file descriptor support.

- Skills: File I/O, buffer management, memory efficiency.

### 4. push_swap

- Goal: Sort a stack of integers using two stacks (a and b) with a limited set of operations (sa, pb, ra, etc.).

- Key Features:

	- Optimized sorting algorithms (e.g., radix sort or chunk-based sorting).

- Skills: Algorithm design, complexity analysis, stack manipulation.

### 5. minitalk

- Goal: Implement client-server communication using UNIX signals (SIGUSR1, SIGUSR2).

- Key Features:

	- Server acknowledges messages.

	- Unicode support.

Skills: Signal handling, bitwise operations, process synchronization.

### 6. FDF

- Goal: Render 3D wireframe landscapes from .fdf files using MiniLibX.

- Key Features:

	- Isometric projection rendering.

- Bonus: Implemented zoom, translation, rotation, and parallel projection.

- Skills: Graphics programming, matrix transformations, event handling.

### 7. NetPractice

- Goal: Configure and troubleshoot simulated network topologies (IP addressing, subnetting, routing).

- Key Features:

	- Successfully solved 10 levels of network topology challenges.

- Skills: TCP/IP fundamentals, subnet masking, network troubleshooting.

🛠️ Common Requirements

Language: C (compiled with -Wall -Wextra -Werror).

Memory Management: No leaks (verified using valgrind).

Makefile: Includes all, clean, fclean and re rules.

Coding Style: Adheres to 42’s Norminette coding standard.

🚀 Explore each project’s directory for source code, Makefiles and detailed documentation!
