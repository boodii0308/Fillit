/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:32:28 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/26 17:13:26 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     dail(int i)
{
	return (i == 1000110001 || i == 10011001 || i == 1100011
			|| i == 11011 || i == 1111  || i == 2001 || i == 1000111
			|| i == 10111 || i == 110010001 || i == 1100010001
			|| i == 100111 || i == 100011001 || i == 111001
			|| i == 100110001 || i == 110011 || i == 1000100011 
			|| i == 11101 || i == 1110001 || i == 100010011) ? 1 : 0;
}

int	back(const char *lol)
{
	int		i;

	i = 0;
	if (!lol)
		return (0);
	while (lol[i])
		i++;
	i--;
	while (lol[i] == '.')
		i--;
	return (i);
}

char *iden(char *dub)
{
	int		i;
	int		len;
	int		g;
	char	*c;

	i = 0;
	g = 0;
	if (!dub)
		return (NULL);
	len = back(dub);
	while (dub[i] == '.')
	{
		i++;
		if (dub[i] == '\0')
			len = i;
	}
	if (!dub || !(c = (char*)malloc(sizeof(char) * (len + 2) - i)))
		return (NULL);
	while (i <= len)
		c[g++] = dub[i++];
	c[g] = '\0';
	return (c);
}

char *actual_size(char *s)
{
	int i;
	int j;
	char *new;

	i = 0;
	sizeofsquare++;
	new = ft_strnew(sizeofsquare * sizeofsquare);
	while(*s)
	{
		new[i++] = *s;
		s++;
		j++;
		if (j == sizeofsquare - 1)
		{
			new[i++] = '.';
			j = 0;
		}
	}
	while (new[i])
		new[i++] = '.';
	new[i] = '\0';
	return (new);
}

char *resize(char *s, int j)
{
	int i;
	char *new;
	int	k;
	int n;
	k = 0;
	n = 0;

	while(s[n])
	{
		if (s[n] == '.')
		{
			while(s[n] == '.')
				n++;
			k++;
		}
		n++;
	}
	n = 0;
	if (j < 0)
	{
		i = -j;
		if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s) - (k * i) + 1))))
			return (0);
		while (*s)
		{
			i = -j;
			while (*s == '.')
			{
				if (i != 0 && *s++ == '.')
					i--;
				else
					new[n++] = *s++;
			}
			new[n++] = *s;
			s++;
		}
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * (ft_strlen(s) + (k * j) + 1))))
			return (0);
		while (*s)
		{
			i = j;
			while(*s == '.')
			{
				new[n++] = *s;
				while (i-- > 0)
					new[n++] = '.';
				s++;
			}
			new[n++] = *s;
			s++;
		}
	}
	new[n] = '\0';
	return (new);
}

char *solve(char **arr)
{
	int i;
	char *yes;
	int l;

	l = 0;
	sizeofsquare++;    
	while ((sizeofsquare * sizeofsquare) < (tetriminos * 4))
		sizeofsquare++;
	i = 0;
	//ft_putnbr(sizeofsquare);
	//ft_putchar('\n');
	
	yes = filler(ft_strnew(sizeofsquare * sizeofsquare), sizeofsquare);
	//ft_putchar('\n');
	
	while(!(match(arr, yes, 0, 1)))
	{
		ft_strdel(&yes);
		sizeofsquare++;
		yes = filler(ft_strnew(sizeofsquare * sizeofsquare), sizeofsquare);
	}
	return (yes);
}
