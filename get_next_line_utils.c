/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:16:09 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/12 15:58:38 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h" 

int	find_new_line(t_list *lst)
{
	int		i;
	t_list	*node;

	if (lst == NULL)
		return (0);
	node = ft_lst_get_last(lst);
	i = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_lst_get_last(t_list *lst)
{
	t_list	*node;

	node = lst;
	while (node && node->next)
		node = node->next;
	return (node);
}

void	malloc_line(char **line, t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_lst(t_list *lst)
{
	t_list	*node;
	t_list	*next;

	node = lst;
	while (node)
	{
		free(node->content);
		next = node->next;
		free(node);
		node = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}
