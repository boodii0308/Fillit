/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:34:36 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/12 00:24:59 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		isitvalidchar(char c)
{
	return (c == '#' || c == '.' || c == '\n') ? 1 : 0;
}

int		valid_square(int fd)
{
	int i;
	int j;
	char buff[1];

	i = 0;
	j = 0;
	while((read(fd, buff, 1)))
	{
	 	if (!(isitvalidchar(buff[0])))
				return (0);
		else if (buff[0] == '\n')
		{
			j++;
			read(fd, buff, 1);
			if (i != 4 || !(isitvalidchar(buff[0])) || (j == 4 && buff[0] != '\n'))
				return (0);
			i = 1;
			if (j == 4 && buff[0] == '\n')
			{
				j = 0;
				tetriminos++;
				i = 0;
				printf("%d\n", tetriminos);
			}
		}	
		else
			i++;
	}
	return (*buff =='\n') ? 1 : 0;
}

int		count_hash(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == '#')
			i++;
		s++;
	}
	return (i == 4) ? 1 : 0;
}

int		valid_file(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(count_hash(s[i])))
			return (0);
		i++;
	}
	return (1);
}
