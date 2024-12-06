/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:49:29 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/04 13:54:47 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 5
#endif

typedef struct s_list
{
    char *content;
    struct s_list *next;
} t_list;


char	*get_next_line(int fd);
int     find_new_line(t_list *lst);
void    generate_line(char **line, t_list *lst);
void    read_and_addlst(int fd, t_list **lst);
void    add_to_lst(t_list **lst, char *buffer, int readed);
void    extract_line(t_list *lst, char **line);
void    clean_lst(t_list **lst);
t_list  *ft_lst_get_last(t_list *lst);
void    free_lst(t_list *lst);
int     ft_strlen(char *s);
#endif
