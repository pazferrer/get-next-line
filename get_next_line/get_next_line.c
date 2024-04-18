/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:29:44 by pferrer-          #+#    #+#             */
/*   Updated: 2024/04/18 19:38:25 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_lecture(int fd)
{
	char	*lecture;
	
	lecture = malloc(10 * sizeof(char));
	if (lecture == NULL)
		return (NULL);
	read(fd, lecture, 10);
	lecture[10] = '\0';
	return (lecture);
}

char	*save_line(char *lecture)
{
	static int		i;
	char	*line;

	i = 0;
	while (lecture[i] && lecture[i] != '\n')
		i++;
	if (lecture[i] == '\n')
		i = i + 1;
	line = malloc(i * sizeof(char));
	if (line == NULL)
		return (NULL);
	line[i--] = '\0';
	while (i >= 0)
	{
		line[i] = lecture[i];
		i--;
	}
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
	line2 = malloc((z - i) * sizeof(char));
	if (line2 == NULL)
		return (NULL);
	z = 0;
	while (lecture[i])
		line2[z++] = lecture[i++];;
	return (line2);
}
/*
char	*get_next_line(int fd)
{
	int			i;
	int			z;
	char		*line;
	char		*lecture;
	static char	*line2;

	i = 0;
	if (fd == -1)
		return (NULL);
	lecture = save_lecture(fd);
	line = save_line(lecture);
	while ((save_line2(lecture, line)) == NULL)
	{
		line = get_next_line(fd);
	}
	if (line2 != NULL)
	{
		line = line2;
		return (line);
	}
	return (line);
}*/


int main() 
{
	int fd;
  fd = open("archivo.txt", O_RDONLY);
    char *lecture = save_lecture(fd);
	char *line = save_line(lecture);
	char *line2 = save_line2(lecture, line);
	//char *getnextline = get_next_line(fd);

    // Imprimir la cadena leída
    printf("Lectura: %s\n", lecture);
	printf("linea: %s\n", line);
	printf("linea2: %s\n", line2);
	//printf("get_next_line es: %s\n", getnextline);

    //free(lecture);
	//free(line2);
   //free(line);	// Liberar la memoria asignada

    return 0;
 
}

