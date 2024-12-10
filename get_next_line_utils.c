/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:16:09 by thodavid          #+#    #+#             */
/*   Updated: 2024/12/10 15:18:10 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h" 

/*			BOOL => if('\n') 1 else 0					*/
int	find_new_line(t_list *lst)
{
	int	i;
	t_list	*line;

	i = 0;

	if(lst == NULL)
		return (0);
	line = ft_lst_get_last(lst);

	while (line->content[i]) 
	{
		if (line->content[i] == '\n')
			return (1);	
		i++;
	}
	return (0);
}

/*              add the content of the buffer to the end of your stash                  */
void    add_to_lst(t_list **lst, char *buffer, int char_)
{
        int     i;
        t_list  *last;
        t_list  *new_node;

        i = 0;
        new_node = malloc(sizeof(t_list));
        if (!new_node)
                return;
        new_node -> next = NULL;
        new_node -> content = malloc(sizeof(char) * (char_ +1));
        if( new_node -> content == NULL)
                return;
        while (buffer[i] && i < char_)
        {
                new_node -> content[i] = buffer[i];
                i++;
        }
        new_node -> content[i] = '\0';
        if(*lst == NULL)
        {
                *lst = new_node;
                return;
        }
        last = ft_lst_get_last(*lst);
        last -> next = new_node;
}


/*              return a pointer to the last node                                       */
t_list  *ft_lst_get_last(t_list *lst)
{
        t_list  *node;

        node = lst;
        while (node && node -> next)
                node = node -> next;
        return (node);
}


/*			len of the current line (with /n) and malloc it			*/
void	generate_line(char **line, t_list *lst)
{
	int	i;
	int	len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst -> content[i])
		{
			if (lst -> content[i] == '\n')
			{
				len ++;
				break;
			}
			len++;
			i++;
		}
		lst = lst -> next;
	}
	*line = malloc(sizeof(char) * (len +1));
	if(!*line)
		return ;
} 

/*              free the entire lst  		                                     	*/
void	free_lst(t_list *lst)
{
	t_list	*current;
	t_list	*next;

	current = lst;
	while (current)
	{
		free(current -> content);
		next = current -> next;
		free(current);
		current  = next;
	}
}

/*		strlen		*/
int	ft_strlen(char *s)
{
	if(!s)
		return (0);
	int	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}
