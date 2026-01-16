#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

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
	int	socketfd = socket(AFINET, SOCK_STREAM, 0);
	if (socketfd < 0)
		exit_error("Fatal error\n");
	fd_max = socketfd;
	//This macro adds the fd to set.
	FD_SET(socketfd, &fds);
	struct sockaddr_in	addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(0x7F000001);
	addr.sin_port = htons(atoi(av[1]));
	if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) || listen(sockfd, 10))
		exit_err("Fatal error\n");
	while (true)
	{
		rfds = wfds = fds;
		if (select(fd_max + 1, &rfds, &wfds, NULL, NULL) < 0)
			exit_err("Fatal error\n");
		for (int fd = 0; fd <= fd_max; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;
			if (fd == socketfd)
			{
				socklen_t	len = sizeof(addr);
				int		client = accept(socketfd, (struct sockaddr *)&addr, &len);
				if (client >= 0)
					add_client(client);
			}
			else
			{
				int	r = recv(fd, rbuf, 1024, 0);
				if (r <= 0)
					remove_client(fd);
				else
				{
					rbuf[r] = '\0';
					msg[fd] = str_join(msg[fd], rbuf);
					serve(fd);
				}
			}
		}
	}

}
