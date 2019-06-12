/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validatin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 10:34:36 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/12 03:20:10 by tebatsai         ###   ########.fr       */
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
int 	dail(int i)
{
	if (i == 1000110001 || i == 10011001 || i == 1100011 || i == 11011)
		return (1);
	else if (i == 1111)
		return (1);
	else if (i == 1000111 || i == 10111 || i == 110010001 || i == 1100010001)
		return (1);
	else if (i == 100111 || i == 100011001 || i == 111001 || i == 100110001)
		return (1);
	else if (i == 110011)
		return (1);
	else
		return (0);
}
int		face_hash(char *s)
{
	int i;
	int z;
	char *c;

	c = "#...#...#...#";
	z = 0;
	i = 0;
	if (!ft_strncmp(s, c, ft_strlen(c)))
		return (1);
	while (*s)
	{
		if(*s == '#')
		{
			if (z > 0)
				i *= 10;
			i++;
			z++;
		}
		else if (z == 4)
			return(dail(i));
		else if (*s == '.')
			i *= 10;
		s++;
	}
	return (0);
}

int		valid_file(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!(count_hash(s[i])) || !(face_hash(s[i])))
			return (0);
		i++;
	}
	return (1);
}
