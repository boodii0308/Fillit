/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:32:28 by tebatsai          #+#    #+#             */
/*   Updated: 2019/07/03 00:50:58 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void 		finishthework(char **arr, char *lol)
{
	int		i;
	char	*yes;
	
	i = 0;
	g_sizeofsquare++;
	while ((g_sizeofsquare * g_sizeofsquare) < (g_tetriminos * 4))
		g_sizeofsquare++;
	yes = filler(ft_strnew((g_sizeofsquare * g_sizeofsquare)), g_sizeofsquare);
	while (!(i))
	{	
		if ((match(arr, yes, 0, 1)))
		{
			print_answer(yes);
			i = 1;
		}
		ft_strdel(&yes);
		g_sizeofsquare++;
		yes = filler(ft_strnew((g_sizeofsquare * g_sizeofsquare)), g_sizeofsquare);
	}
	ft_strdel(&yes);
	ft_strdel(&lol);
	while (arr[i])
		ft_strdel(&arr[i++]);
}
