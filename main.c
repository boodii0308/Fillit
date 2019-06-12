/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:21:24 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/12 00:22:37 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			**get_array(int fd)
{
	int i;
	int k;
	int j;
	char **arr;
	char buff[1];

	arr = ft_create_arr(tetriminos, 16);
	i = 0;
	j = 0;
	k = 0;
	while (read(fd ,buff, 1))
	{
		if (k == 4)
		{
			k = 0;
			arr[i++][j] = '\0';			
			j = 0;
		}
		else if (buff[0] == '\n')
			k++;
		else
			arr[i][j++] = buff[0];
	}
	return (arr);
}

void				print_arr(char **s)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < tetriminos)
	{
		j = 0;
		while(s[i][j])
		{
			ft_putchar(s[i][j]);
			j++;
			if (j % 4 == 0)
				ft_putchar('\n');
		}
		ft_putchar('\n');
		i++;
	}
}

int					main(int arc,char **arv)
{
	int fd;
	char **arr;
	char *lol;
	int l;
	int i;

	i = 0;
	if(arc == 2)
	{
		lol  = ft_strdup(arv[1]);
		fd = open(arv[1], O_RDONLY);
		if (valid_square(fd))
		{
			l = open(lol, O_RDONLY);
			arr = get_array(l);
			if (valid_file(arr))
				print_arr(arr);
		}
		else
		{
			close(fd);
			ft_putstr("error\n");
		}
	}
	return (0);
}
