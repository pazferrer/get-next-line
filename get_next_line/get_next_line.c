/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:29:44 by pferrer-          #+#    #+#             */
/*   Updated: 2024/05/04 13:26:43 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_lecture(int fd, char *reading)
{
	char	*lecture;
	int		i;
	int		z;

	i = 0;
	z = 0;
	lecture = malloc(11 * sizeof(char));
	if (lecture == NULL)
		return (NULL);
	reading = NULL;
	while (newline_search(lecture) == 0)
	{
		z = read(fd, lecture, 10);
		lecture[z] = '\0';
		reading = join_string(reading, lecture);
	}
	printf("Lectura: %s\n", reading);
	return (reading);
}

char	*save_line(char *lecture)
{
	int		i;
	char	*line;

	i = 0;
	while (lecture[i] && lecture[i] != '\n' && lecture[i] != '\0')
		i++;
	if (lecture[i] == '\n')
		i = i + 1;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[i--] = '\0';
	while (i >= 0)
	{
		line[i] = lecture[i];
		i--;
	}
	printf("linea: %s\n", line);
	return (line);
}

char	*save_line2(char *lecture, char *line)
{
	int		i;
	int		z;
	char	*line2;

	i = 0;
	z = 0;
	while (line[i] == lecture[i] && line[i])
		i++;
	z = i;
	while (lecture[z])
		z++;
	if (lecture[i] == '\0')
		return (NULL);
	line2 = malloc((z - i + 1) * sizeof(char));
	if (line2 == NULL)
		return (NULL);
	z = 0;
	while (lecture[i])
		line2[z++] = lecture[i++];;
	line2[z] = '\0';
	printf("linea2: %s\n", line2);
	return (line2);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*line;
	char		*lecture;
	static char	*line2;

	i = 0;
	if (fd == -1)
		return (NULL);
	if (line2 != NULL && line2[i])
	{
		lecture = save_lecture(fd, line2);
		//printf("if: %s", line2);
	}
	else
	{
		line2 = NULL;
		lecture = save_lecture(fd, line2);
		//printf("else: %s", lecture);
	}
	line = save_line(lecture);
	line2 = save_line2(lecture, line);
	return (line);
}

/*
int main() 
{
	int fd;
  fd = open("archivo.txt", O_RDONLY);
  	//char *line2 = NULL;
    //char *lecture = save_lecture(fd, line2);
	//char *line = save_line(lecture);
	//line2 = save_line2(lecture, line);
	char *getnextline = get_next_line(fd);

    // Imprimir la cadena leída
   //printf("Lectura: %s\n", lecture);
	//printf("linea: %s\n", line);
	//printf("linea2: %s\n", line2);
	printf("get_next_line es: %s\n", getnextline);

    //free(lecture);
	//free(line2);
   //free(line);	// Liberar la memoria asignada

    return 0;
 
}*/

