/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebatsai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:55:03 by tebatsai          #+#    #+#             */
/*   Updated: 2019/06/26 22:15:25 by tebatsai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
int tetriminos;
int sizeofsquare;
int fibonacci;

#include "./libft/libft.h"

char	**get_array(int fd);
void	print_arr(char **s);
void	print_answer(char *s);
void	finish_him(int l, int fd, char **arr, char *lol);
int		main(int arc, char **arv);
int		isitvalidchar(char c);
int		valid_square(int fd);
int		count_hash(char *s);
int		face_hash(char *s);
int		valid_file(char **s);
int		dial(int i);
int		back(const char *lol);
char 	*iden(char *dub);
char 	*actual_size(char *s);
char	*resize(char *s, int j);
void	solve(char **arr);
char 	*build(char l, char *s);
char 	*kicker(int i, char *c, char *s);
char	*filler(char *yes, int i);
int 	match(char **c, char *s, int lol, int t);
char 	*news(char c, char *s);
int		check_this(char *c, char *s, int t);
int		hash_counter(char *c, int d);
int		changer(char *c, char *s, int t);
#endif
