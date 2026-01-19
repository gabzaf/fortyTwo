#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	fd_max = 0, clients = 0;
fd_set	fds, rfds, wfds;
int	id[10000];
char	*msg[10000];
char	wbuf[42], rbuf[1024];

int	extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = (char *)calloc(1, sizeof(*newbuf)*(strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*str_join(char *buf, char *add)
{
	char	*newbuf;
	int	len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = (char *)malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void	exit_err(char *err)
{
	write(2, err, strlen(err));
	exit(1);
}

void	notify(int from, char *msg)
{
	for (int fd = 0; fd <= fd_max; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != from)
			send(fd, msg, strlen(wbuf), 0);
	}
}

void	add_client(int fd)
{
	fd_max = fd > fd_max ? fd : fd_max;
	FD_SET(fd, &fds);
	id[fd] = clients++;
	msg[fd] = NULL;
	sprintf(wbuf, "server: client %d just arrived\n", id[fd]);
	notify(fd, wbuf);
}

void	remove_client(int fd)
{
	sprintf(wbuf, "server: client %d disconnected\n", id[fd]);
	notify(fd, wbuf);
	free(msg[fd]);
	msg[fd] = NULL;
	FD_CLR(fd, &fds);
	close(fd);
}

void	serve(int fd)
{
	char	*str;
	while (extract_message(&msg[fd], &str))
	{
		sprintf(wbuf, "client %d:", id[fd]);
		notify(fd, wbuf);
		notify(fd, str);
		free(str);
		str = NULL;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_err("Wrong nbr of args\n");
	//This macro removes all fds from set. It should be employed as the 1st step in initializing a fd set.
	FD_ZERO(&fds);
	//Creates TCP socket sing IPv4
	int	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd < 0)
		exit_err("Fatal error\n");
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
	if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) || listen(socketfd, 10))
		exit_err("Fatal error\n");
	//Starts the event-driven infinite loop
	while (1)
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
