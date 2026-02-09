# mini_serv: Multiplexed TCP Chat Server

A lightweight, single-threaded chat server implemented in C using **I/O Multiplexing**. This project demonstrates the ability to manage multiple concurrent client connections without the use of threads,
ensuring non-blocking communication on a single process.

---

## 🚀 Overview

`mini_serv.c` listens for incoming TCP connections on `127.0.0.1` at a specified port. It facilitates real-time communication between all connected clients, assigning each a unique ID and broadcasting
messages across the network.



### Key Features
* **Multiplexing with select()**: Efficiently monitors multiple file descriptors simultaneously.
* **Non-blocking Communication**: Handles "lazy" clients and partial messages without stalling the server.
* **ID System**: Automatically assigns incremental IDs (starting from 0) to new clients.
* **Broadcasting**: Notifies all participants when a user joins, leaves or sends a message.

---

## 🛠 Technical Specifications

### Requirements
* **Language**: C
* **Allowed Functions**: write, close, select, socket, accept, listen, send, recv, bind, strstr, malloc, realloc, free, calloc, bzero, atoi, sprintf, strlen, exit, strcpy, strcat, memset.

### Logic Flow
1.  **Initialization**: Creates a TCP socket and binds it to the localhost IP and the user-provided port.
2.  **The Select Loop**: 
    * The server waits for activity on any registered file descriptor.
    * If the activity is on the server socket, a new client is accepted.
    * If the activity is on a client socket, the server reads data using recv().
3.  **Message Buffering**: Since TCP is a stream protocol, the server uses extract_message() to handle split packets and ensure messages are only broadcast when a newline \n is encountered.
4.  **Cleanup**: Properly closes sockets and frees allocated memory upon client disconnection to prevent leaks.

---

## 💻 Usage & Testing

### Compilation
gcc -Wall -Wextra -Werror mini_serv.c -o mini_serv

### Execution
./mini_serv 1234

### Testing
Connect using netcat (nc) from multiple terminal windows:
nc 127.0.0.1 1234

---

## 📝 Error Handling

| Scenario | Output (stderr) | Exit Status |
| :--- | :--- | :--- |
| Missing port argument | Wrong number of arguments\n | 1 |
| System call failure | Fatal error\n | 1 |
| Memory allocation failure | Fatal error\n | 1 |

---

## ⚠️ Important Notes
* **No Preprocessors**: The code strictly avoids #define as per requirements.
* **Memory Management**: Each client has a dedicated heap-allocated buffer to store partial messages, ensuring no data is lost between select() calls.
