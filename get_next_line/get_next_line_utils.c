/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:36:33 by pferrer-          #+#    #+#             */
/*   Updated: 2024/05/10 20:07:53 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	{
		free(string1);
		return (NULL);
	}
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

char	*read_liberator(int z, char *lecture, char *reading)
{
	if (z == -1)
	{
		free(lecture);
		free(reading);
		return (NULL);
	}
	if (z == 0)
	{
		free(lecture);
		return (reading);
	}
	if (lecture == NULL)
	{
		free(reading);
		return (NULL);
	}
	if (z == 2)
	{
		free(lecture);
		return (NULL);
	}
	free(lecture);
	return (reading);
}

int	newline_search(char *lecture)
{
	int	i;

	i = 0;
	while (lecture[i] != '\n' && lecture[i])
		i++;
	if (lecture[i] == '\n')
		return (1);
	return (0);
}
