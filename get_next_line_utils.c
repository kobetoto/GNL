/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:16:09 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/02 17:43:43 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h> 


int	ft_end_line(char *s)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if (s[i] == '\n')
			return 1;
		else 
			return -1;
	}
	return (0);
}

int main()
{
	char *s = "hello\nbye";
	printf("\nreturn value of ft_end_line ===%i===\n", ft_end_line(s));

}
