#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	fd_max = 0;
fd_set	fds, rfds, wfds;

char	*str_join(char *buf, char *add)
{

}

void	exit_err(char *err)
{
	write(2, err, strlen(err));
	exit(1);
}

void	add_client()
{

}

void	remove_client(int fd)
{

}

void	serve(int fd)
{

}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_err("Wrong nbr of args\n");
	//This macro removes all fds from set. It should be employed as the 1st step in initializing a fd set.
	FD_ZERO(&fds);
	//Creates TCP socket sing IPv4
	int	socketfd = socket(AFINET, SOCK_STREAM, 0);
	if (socketfd < 0)
		exit_error("Fatal error\n");
	//Initialize fd_max with the server socket fd, used by select
	fd_max = socketfd;
	//This macro adds the socket fd to set.
	FD_SET(socketfd, &fds);
	//Declares a struct to store IPv4 socket address info
	struct sockaddr_in	addr;
	//Zeroes out the address struct to avoid garbage values
	bzero(&addr, sizeof(addr));
	//Specifies IPv4 as the address family
	addr.sin_family = AF_INET;
	//Sets the IP address to 127.0.0.1, converted to network byte order
	addr.sin_addr.s_addr = htonl(0x7F000001);
	//Sets the port number from the cli arg, converting to network byte order
	addr.sin_port = htons(atoi(av[1]));
	//Binds the socket to the given IP/port and starts listening with a backlog of 10
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) || listen(sockfd, 10))
		exit_err("Fatal error\n");
	//Starts the event-driven infinite loop
	while (true)
	{
		//Copies the master fd set into read and write sets for select
		rfds = wfds = fds;
		//Waits until at least one fd is ready for reading or writing
		if (select(fd_max + 1, &rfds, &wfds, NULL, NULL) < 0)
			exit_err("Fatal error\n");
		//Iterates over all possible fd up to the maximum
		for (int fd = 0; fd <= fd_max; fd++)
		{
			//Checks if this fd is not ready for reading
			if (!FD_ISSET(fd, &rfds))
				continue;
			//Checks if the ready descriptor is the server socket
			if (fd == socketfd)
			{
				//Initializes the length of the address struct
				socklen_t	len = sizeof(addr);
				//Accepts a new incoming client connection
				int		client = accept(socketfd, (struct sockaddr *)&addr, &len);
				if (client >= 0)
					//Registers the new client
					add_client(client);
			}
			//Otherwise the ready descriptor belongs to an existing client
			else
			{
				//Receives up to 1024 bytes of data from the client
				int	r = recv(fd, rbuf, 1024, 0);
				if (r <= 0)
					remove_client(fd);
				else
				{
					rbuf[r] = '\0';
					//Appends the received data to the client's existing message buffer
					msg[fd] = str_join(msg[fd], rbuf);
					serve(fd);
				}
			}
		}
	}
}

/*
 * Summary of code blocks

1. Argument validation: Ensures the program is launched with exactly one argument (the port number).

2. Socket setup: Creates a TCP socket, initializes address information, binds to 127.0.0.1:port, and starts listening for connections.

3. File descriptor management: Uses fd_set and select() to monitor multiple sockets simultaneously without multithreading.

4. Server loop: Continuously waits for socket activity and reacts accordingly.

5. New client handling: Accepts incoming connections and registers new clients.

6. Client communication: Receives data from clients, accumulates messages, processes them, and removes clients on disconnect.

Overall summary

This program implements a single-threaded, multiplexed TCP server using select().
It listens on localhost at a port provided via CLI.
It supports multiple simultaneous clients without using threads.

The server:
- Accepts new connections
- Receives and buffers client messages
- Processes messages via serve()
- Cleans up disconnected clients

File descriptors are centrally managed using fd_set, making the server efficient and scalable for a moderate number of clients.
This structure is typical of event-driven network servers, such as simple chat servers or IRC-style projects.*/
