/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:44:32 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/02 17:45:00 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "get_next_line.h"
#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 24
#endif


/*
 * 	si BUFFER not define au moment de la compilation avec (cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c)
 * 		define BUFFER_SIZE = 24
 *	var line 	:  la ligne a retourner et donc lue par read 
 *	var copy_tmp	:  copie en cours
 *
 *
 *
 *	 RETURN 
 *	 	Le contenu de la ligne lue : comportement correct
 *	 	NULL : rien d’autre à lire ou une erreur s’est produite
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*copy_tmp;
	char		*buffer;
	size_t		read_rslt;

	if (fd < 0)
		return (NULL);

	buffer = malloc(sizeof(char) * BUFFER_SIZE +1);
	if (!buffer)
		return (NULL);
	
	read_rslt = read(fd, buffer, BUFFER_SIZE);
	if(read_rslt <= 0)
	{
		free(buffer);
		return (NULL);
	}
	else if(read_rslt == BUFFER_SIZE)
	{
		//function qui permet de savoir si on et en fin de ligne 
	}

	//RETURN
		//Le contenu de la ligne lue : comportement correct
		//NULL : rien d’autre à lire ou une erreur s’est produite
	
}
