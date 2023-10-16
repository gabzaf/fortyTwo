/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gamado-x <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 09:22:29 by gamado-x          #+#    #+#             */
/*   Updated: 2023/10/13 11:04:24 by gamado-x         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int	main(void)
{
	int	err;
	//char	*env[] = { "TEST=environment variable", NULL };
	char	*arr[] = { "ping", "google.com", NULL };
	
	//execl("/usr/bin/ping", "/usr/bin/ping", "google.com", NULL);
	//execlp("ping", "ping", "google.com", NULL);
	execvp("ping", arr);
	//execvpe("ping", arr, env);
	err = errno;
	printf("Ping finished executing\n");
	return (0);
}
