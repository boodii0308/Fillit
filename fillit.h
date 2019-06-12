/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:55:03 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/12 00:21:02 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
int tetriminos;

#include "./libft/libft.h"

char		**get_array(int fd);
int		valid_square(int fd);
int		isitvalidchar(char c);
void	print_arr(char **s);
int		count_hash(char *s);
int		valid_file(char **s);
#endif
