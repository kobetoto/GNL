/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:50:16 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/04 13:58:54 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "get_next_line.h"

char    *get_next_line(int fd);

int main()
{
	int fd; 
	char	*line;

	fd = open( "text.txt", O_RDONLY);


	if(fd < 0)
	{
		perror("Erreur lors de l'ouverture");
		return 1;
	}

	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("\ngnl is ===%s===\n", line);
		free(line);
	}
	return (0);
}














/*
   int main ()
   {
   char 	buff[256];
   int	open_rslt;

//je stock le fd que me renvoie open() 
open_rslt = open( "text.txt", O_RDONLY);
// si fd < 0 alors erreur
if(open_rslt < 0)
{
perror("Erreur lors de l'ouverture");
return 1;
}
int i = 0;
while (i < 3)
{
int returnOfRead = read(open_rslt, buff, 5);
printf("return of read ==%i==\n", returnOfRead);
if (end_line(buff) == 1)
return 0;
printf("buff is ==%s==\n\n\n", buff);
i++;
}
}
*/
