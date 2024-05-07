/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:36:33 by pferrer-          #+#    #+#             */
/*   Updated: 2024/05/07 20:10:27 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	length_string(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (0);
	while (string[i])
		i++;
	return (i);
}

char	*join_string(char *string1, char *string2)
{
	int		i;
	int		j;
	int		y;
	char	*joint;

	i = length_string(string1) + length_string(string2);
	joint = malloc((i + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	j = 0;
	while (string1 && string1[j])
	{
		joint[j] = string1[j];
		j++;
	}
	y = 0;
	while (string2[y])
		joint[j++] = string2[y++];
	joint[j] = '\0';
	return (joint);
}

int	newline_search(char *lecture, int fd)
{
	int	i;

	i = 0;
	while (lecture[i] != '\n' && lecture[i])
	{
		i++;
		//if (lecture[i] == '\0')
		//	fd++;
		//if (!fd)
		//	fd--;
		//	return(0);
	}
	if (lecture[i] == '\0')
		fd++;
	if (lecture[i] == '\n')
		return (1);
	return (0);
}
