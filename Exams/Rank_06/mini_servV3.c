#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

int	fd_max = 0, clients = 0;
fd_set	fds, rfds, wfds;
char	msg[100000];
char	id[100000];
char	wbuf[42], rbuf[1024];

void	exit_err(char *str)
{
	write(2, str, strlen(str));
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
	id[fd] = client++;
	msg[fd] = NULL;
	sprintf(wbuf, "server: client %d just arrived\n", id[fd]);
	notify(fd, wbuf);
}

void	remove_client(int fd)
{
	sprintf(wbuf, "server: client %d just left\n", id[fd]);
	notify(fd, wbuf);
	free(msg);
	msg[fd] = NULL;
	FD_CLR(fd, &fds);
	close(fd);
}

void	*str_join(char *buf, char *add)
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

void	extract_message(char **msg, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i] == '\n')
	{
		if ((*buf[i] == '\n'))
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

void	serve(int fd)
{
	char	*str;
	while (extract_message(&msg[fd], &str))
	{
		sprint(wbuf, "client %d", id[fd]);
		notify(fd, wbuf);
		notify(fd, str);
		free(str);
		str = NULL;
	}
}

int	main(int ac, char **av)
{
	if (ac != 2)
		exit_err("Wrong number of arguments\n");
	FD_ZERO(&fds);
	int	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	if (socketfd < 0)
		exit_err("Fatal error\n");
	fd_max = socketfd;
	FD_SET(socketfd, &fds);
	struct sockaddr_in	addr;
	bzero(&addr, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(0x7F000001);
	addr.sin_port = htons(atoi(av[1]));
	if (bind(socketfd, (struct sockaddr *)&addr, sizeof(addr)) || listen(socketfd, 10))
			exit_err("Fatal error\n");
	while (1)
	{
		rfds = wfds = fds;
		if (select(fd_max + 1, &rfds, &wfds, NULL, NULL)  < 0)
			exit_err("Fatal error\n");
		for (int fd = 0; fd <= fd_max; fd++)
		{
			if (!FD_ISSET(fd, &fds))
				continue;
			if (socketfd == fd)
			{
				socklen_t	len = sizeof(addr);
				int	client = accept(socketfd, (struct sockaddr *)&addr, &len);
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

	return (0);
}
