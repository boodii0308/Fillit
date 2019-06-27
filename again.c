/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   again.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 21:16:33 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/26 19:53:08 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int match(char **arr, char *s, int lol, int fibonacci)
{
	char *smalltet;
	int i;
	int y;
	
//	print_answer(s);
//	ft_putchar('\n');
	if (lol == tetriminos)
	{
		print_answer(s);
		return (1);
	}
	y = sizeofsquare - 4;
	smalltet = ft_strcpy(ft_strnew(ft_strlen(iden(arr[lol]))), iden(arr[lol]));
	if (y != 0)
		smalltet = ft_strdup(resize(smalltet, y));
 	if (changer(smalltet, s, fibonacci))
	{
 		i = check_this(smalltet, s, fibonacci);
		build('A' + lol,kicker(i,smalltet, s));
		return (match(arr, s, ++lol, 1)) ? 1 : match(arr, news('A' + (lol - 1), s), lol - 1, ++fibonacci);
	}
	return (0);
}

char *news(char c, char *s)
{
	int i;
	char *new;
	
	new = ft_strnew(ft_strlen(s));
	i = 0;
	while (*s)
	{
		while (*s >= c)
		{
			new[i++] = '.';
			s++;
		}
		new[i++] = *s;
		s++;
	}
	new[i] = '\0';
	return (new);
}
int check_this(char *c, char *s, int t)
{
	int i;
	int d;
	int j;

	j = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		j = hash_counter(c, d);
		while((c[d] == '.' && (ft_isalpha(s[i]) || s[i] == '.')) 
			||((c[d] == '#' && s[i] == '.' && i % sizeofsquare + j <= sizeofsquare)))
		{
			j = 0;
			i++;
			d++;
			if (c[d] == '\0' && t != 1)
			{
				i -=d - 1;
				t--;
				d = 0;
			}
			j = hash_counter(c, d);
			if (c[d] == '\0' && t == 1)
				return (i - d);
		}
		i -= d;
		d = 0;
		if ((ft_strlen(c) + i) > ft_strlen(s))
			return (0);
		i++;
	}
	return (0);
}

int hash_counter(char *c, int d)
{
	int i;

	i = 0;
	while (c[d] == '#')
	{
		i++;
		d++;
	}
	return (i);
}
int changer(char *c, char *s, int t)
{
	int i;
	int d;
	int j;

	j = 0;
	d = 0;
	i = 0;
	while (s[i])
	{
		j = hash_counter(c, d);
		while((c[d] == '.' && (ft_isalpha(s[i]) || s[i] == '.'))
				|| (c[d] == '#' && s[i] == '.' && i % sizeofsquare + j <= sizeofsquare))
		{
			j = 0;
			i++;
			d++;
			if (c[d] == '\0' && t != 1)
			{
				i -=d - 1;
				t--;
				d = 0;
			}
			j = hash_counter(c, d);
			if (c[d] == '\0' && t == 1)
				return (1);
		}
		i -= d;
		d = 0;
		if ((ft_strlen(c) + i) > ft_strlen(s))
			return (0);
		i++;
	}
	return (0);
}
