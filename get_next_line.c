/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:44:32 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/10 15:04:05 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);


		/*	steps	*/

	/* 1. read from fd and add to lst	*/
	read_and_addlst(fd, &lst);
	if(lst == NULL)
		return (NULL);

	/* 2. extract from lst to line		*/
	list_to_line(lst, &line);

	/* 3. clean lst				*/
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

/*              1. read and add to lst 						   */
void    read_and_addlst(int fd, t_list **lst)
{
	char	*buffer;
	int		char_;

	char_ = 1;
	while (!find_new_line(*lst) && char_ != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE +1));
		if (!buffer)
			return;
		char_ = (int)read(fd, buffer, BUFFER_SIZE);

		if((*lst == NULL && char_ == 0) || char_ == -1)
		{
			free(buffer);
			return;
		}
		buffer[char_] = '\0';
		add_to_lst(lst, buffer, char_);
		free(buffer);
	}
}


/*              2. extract all char from lst and add it to line  (stop after the \n)   */

void    list_to_line(t_list *lst, char **line)
{
	int     i;
	int     j;

	if(lst == NULL)
		return;
	generate_line(line, lst);
	if (*line == NULL)				
		return;
	j = 0;
	while (lst)
	{
		i = 0;
		while(lst -> content[i])
		{
			if(lst -> content[i] == '\n')
			{
				(*line)[j++] = lst-> content[i];
				break;
			}
			(*line)[j++] = lst -> content[i++];
		}

		lst = lst -> next;
	}
	(*line)[j] = '\0';
}



/*              3.clean the char who was read (so clear the stash                         )*/

void    clean_lst(t_list **lst)
{
	t_list  *last;
	t_list  *clean_node;
	int     i;
	int     j;

	i = 0;
	if (lst == NULL)
		return;
	clean_node = malloc(sizeof(t_list));
	if(!clean_node)
		return;
	clean_node -> next = NULL;
	last = ft_lst_get_last(*lst);
	while (last -> content[i] && last -> content[i] != '\n')
		i++;
	if (last -> content && last -> content[i] == '\n')
		i++;
	clean_node -> content = malloc(sizeof(char) * ((ft_strlen(last -> content) - i) +1));
	if (clean_node -> content == NULL)
		return;
	j = 0;
	while(last -> content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node -> content[j] = '\0';
	free_lst(*lst);
	*lst  = clean_node;

}
