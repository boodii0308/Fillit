/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:55:03 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/25 01:16:06 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
int tetriminos;
int sizeofsquare;
int fibonacci;

#include "./libft/libft.h"

char	**get_array(int fd);
int		valid_square(int fd);
int		isitvalidchar(char c);
void	print_arr(char **s);
int		count_hash(char *s);
int		valid_file(char **s);
int		face_hash(char *s);
char	*solve(char **arr);
int		dail(int i);
void	print_answer(char *s);
char	*resize(char *s, int j);
char 	*build(char l, char *s);
int 	match(char **c, char *s, int lol, int t);
char	*filler(char *yes, int i);
char 	*actual_size(char *s);
int		position_checker(char *c, char *s);
char 	*iden(char *dub);
char 	*kicker(int i, char *c, char *s);
char 	*news(char c, char *s);
int		check_this(char *c, char *s, int t);
int		changer(char *c, char *s, int t);
int		hash_counter(char *c, int d);
#endif
