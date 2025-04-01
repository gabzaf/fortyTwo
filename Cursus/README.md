# 📌 Cursus (Core Projects)

This section contains the core projects of the 42 curriculum, designed to develop foundational skills in C programming, algorithms, systems programming, and problem-solving. Below is an overview of each project, highlighting key objectives, technical aspects, and acquired skills.

## 🧩 Projects

### 1. Libft

- Goal: Create a custom C library by reimplementing standard functions (libc) and additional utilities.

- Key Features:

	- Implemented 42+ functions, including ft_strlen, ft_substr, ft_split, and memory management tools.

	- Bonus: Linked list manipulation (ft_lstnew, ft_lstadd_back).

- Skills: Memory management, static libraries, defensive programming.

### 2. Born2beRoot

- Goal: Set up a secure Debian/Rocky Linux server in a virtual machine with strict system administration rules.

- Key Tasks:

	- Install a minimal OS (Debian/Rocky) without a graphical interface.

	- Configure LVM with 2+ encrypted partitions.

	- Implement SSH on port 4242 (root login disabled).

	- Set up UFW/firewalld (only port 4242 open).

	- Enforce strong password policies (e.g., 10+ chars, expiry every 30 days).

	- Configure sudo with logging, TTY mode, and restricted paths.

	- Create a monitoring.sh script to display system stats every 10 minutes.

- Skills Gained:

	- Virtualization (VirtualBox/UTM), partitioning, user/group management.

	- Security hardening (SELinux/AppArmor, firewall, sudo policies).

	- Bash scripting, cron jobs and system monitoring.

### 3. ft_printf

- Goal: Recode the printf function, handling various conversions (c, s, p, d, i, u, x, X, %).

- Key Features:

	- Variadic arguments (va_list) and dynamic string formatting.

	- Bonus: Supported flags (-0.# +) and minimum width formatting.

- Skills: Parsing, bit manipulation, edge-case handling.

### 4. get_next_line

- Goal: Read a file line by line using a static variable and dynamic memory allocation.

- Key Features:

	- Single static variable implementation.

	- Bonus: Multi-file descriptor support.

- Skills: File I/O, buffer management, memory efficiency.

### 5. push_swap

- Goal: Sort a stack of integers using two stacks (a and b) with a limited set of operations (sa, pb, ra, etc.).

- Key Features:

	- Optimized sorting algorithms (e.g., radix sort or chunk-based sorting).

- Skills: Algorithm design, complexity analysis, stack manipulation.

### 6. minitalk

- Goal: Implement client-server communication using UNIX signals (SIGUSR1, SIGUSR2).

- Key Features:

	- Server acknowledges messages.

	- Unicode support.

Skills: Signal handling, bitwise operations, process synchronization.

### 7. FDF

- Goal: Render 3D wireframe landscapes from .fdf files using MiniLibX.

- Key Features:

	- Isometric projection rendering.

- Bonus: Implemented zoom, translation, rotation, and parallel projection.

- Skills: Graphics programming, matrix transformations, event handling.

### 8. NetPractice

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
