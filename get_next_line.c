/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:44:32 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/04 16:51:03 by thodavid         ###   ########.fr       */
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

	/* 2. extract from stash to line	*/
	extract_line(lst, &line);

	/* 3. clean stash			*/
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

