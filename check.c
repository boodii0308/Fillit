/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 16:07:21 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/01 23:04:39 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*build(char l, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			s[i] = l;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*kicker(int i, char *c, char *s)
{
	int		j;

	j = 0;
	while (s[i])
	{
		if (c[j] == '#' && s[i] == '.')
		{
			s[i] = c[j];
			j++;
		}
		if (ft_isalpha(s[i]) && c[j] == '.')
		{
			j++;
		}
		if (s[i] == '.' && c[j] == '.')
		{
			s[i] = c[j];
			j++;
		}
		if (c[j] == '\0')
			return (s);
		i++;
	}
	return (NULL);
}

int			deleteit(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
		return (1);
	}
	return (0);
}

char		*filler(char *yes, int i)
{
	int		l;

	l = i * i;
	yes[l--] = '\0';
	while (l >= 0)
	{
		yes[l] = '.';
		l--;
	}
	return (yes);
}

char		*news(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= c)
		{
			s[i] = '.';
		}
		i++;
	}
	s[i] = '\0';
	return (s);
}
