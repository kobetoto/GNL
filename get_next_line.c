/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:44:32 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/12 15:56:41 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (lst = NULL, NULL);
	read_and_add(fd, &lst);
	if (lst == NULL)
		return (NULL);
	list_to_line(lst, &line);
	clean_lst(&lst);
	if (line[0] == '\0')
	{
		free_lst(lst);
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

void	read_and_add(int fd, t_list **lst)
{
	char	*buf;
	int		char_;

	char_ = 1;
	while (!find_new_line(*lst) && char_ != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		char_ = (int)read(fd, buf, BUFFER_SIZE);
		if ((*lst == NULL && char_ == 0) || char_ == -1)
		{
			free(buf);
			return ;
		}
		buf[char_] = '\0';
		add_to_lst(lst, buf, char_);
		free(buf);
	}
}

void	add_to_lst(t_list **lst, char *buf, int char_)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (char_ + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < char_)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	last = ft_lst_get_last(*lst);
	last->next = new_node;
}

void	list_to_line(t_list *lst, char **line)
{
	int	i;
	int	j;

	if (lst == NULL)
		return ;
	malloc_line(line, lst);
	if (*line == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				(*line)[j++] = lst->content[i];
				break ;
			}
			(*line)[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

void	clean_lst(t_list **lst)
{
	t_list	*last;
	t_list	*cln;
	int		i;
	int		j;

	cln = malloc(sizeof(t_list));
	if (lst == NULL || cln == NULL)
		return ;
	cln->next = NULL;
	last = ft_lst_get_last(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	cln->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (cln->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		cln->content[j++] = last->content[i++];
	cln->content[j] = '\0';
	free_lst(*lst);
	*lst = cln;
}
