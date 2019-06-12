/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:50:26 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/11 10:21:17 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char 
int main(int arc, char **arv, char **envp)
{
	int fd;
	char *t;

	if(arc == 2)
	{
		printf("Enviroment Pointer: %p\n", envp);	
		t = arv[1];
		fd = open(t, O_RDONLY);
		get_array(fd, &t);
	}
	return (0);
}
