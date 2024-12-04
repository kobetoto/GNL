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
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 5
#endif

typedef struct	s_list
{
	char		*content;
	struct s_list	*next;
}		t_list;

char	*get_next_line(int fd);
int     found_newLine(t_list *stash);
void    generate_line(char **line, t_list *stash);
void    read_and_stash(int fd, t_list **stash, int *readed_ptr);
void    add_to_stash(t_list **stash, char *buffer, size_t readed);
void    extract_line(t_list *stash, char **line);
void    clean_stash(t_list **stash);
t_list  *ft_lst_get_last(t_list *stash);
void    free_stash(t_list *stash);
int     ft_strlen(char *s);
