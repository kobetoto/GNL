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
	/*	variables	*/
	static t_list	*stash;
	char		*line;
	int		readed;

	/*	gestions des arguments	*/
	if (fd < 0 || BUFFER_SIZE <= 0) //si le fichier on na pas le droit de le lire 
		return (NULL);

	readed = 1;
	line = NULL;



	/*	steps	*/

	// 1. read from fd and add to stash
	read_and_stash(fd, &stash, &readed);
	if(stash == NULL)
		return (NULL);
	// 2. extract from stash to line
	extract_line(stash, &line);
	// 3. clean stash
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL; 
		free(line);
		return (NULL);
	}
	return (line);
}
