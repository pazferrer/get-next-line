/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:29:44 by pferrer-          #+#    #+#             */
/*   Updated: 2024/05/10 20:07:56 by pferrer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_lecture(int fd, char *reading)
{
	char	*lecture;
	char	*tmp;
	int		z;

	z = 0;
	lecture = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (lecture == NULL)
		return (read_liberator(1, lecture, reading));
	lecture[0] = '\0';
	while (newline_search(lecture) == 0)
	{
		z = read(fd, lecture, BUFFER_SIZE);
		if (z == -1 || z == 0)
		{
			return (read_liberator(z, lecture, reading));
		}
		lecture[z] = '\0';
		tmp = join_string(reading, lecture);
		if (tmp == NULL)
			return (read_liberator(2, lecture, reading));
		free(reading);
		reading = tmp;
	}
	return (read_liberator(1, lecture, reading));
}

char	*save_line(char *lecture)
{
	int		i;
	char	*line;

	i = 0;
	while (lecture[i] && lecture[i] != '\n')
		i++;
	if (lecture[i] == '\n')
		i = i + 1;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
	{
		free(lecture);
		return (NULL);
	}
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
	while (line[i] == lecture[i] && line[i])
		i++;
	if (lecture[i] == '\0')
		return (NULL);
	z = i;
	while (lecture[z])
		z++;
	line2 = malloc((z - i + 1) * sizeof(char));
	if (line2 == NULL)
	{
		line = NULL;
		lecture = NULL;
		return (NULL);
	}
	z = 0;
	while (lecture[i])
		line2[z++] = lecture[i++];
	line2[z] = '\0';
	return (line2);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*lecture;
	static char	*line2;

	if (fd == -1)
		return (NULL);
	lecture = save_lecture(fd, line2);
	if (lecture == NULL)
	{
		line2 = NULL;
		return (NULL);
	}
	line = save_line(lecture);
	if (line == NULL)
	{
		line2 = NULL;
		return (NULL);
	}
	line2 = save_line2(lecture, line);
	if (line2 == NULL && line == NULL && lecture == NULL)
		return (read_liberator(-1, line, lecture));
	free(lecture);
	return (line);
}

/*
int main() 
{
	int		fd;
	char	*lecture
	char	*line;
	char	*line2;
	char	*getnextline;

//	fd = open("archivo.txt", O_RDONLY);
	fd = open("test", O_RDONLY);
	printf("ARCHIVO fd: %d\n", fd);

  	//line2 = NULL;
    //lecture = save_lecture(fd, line2);

	//line = save_line(lecture);

	//line2 = save_line2(lecture, line);

	getnextline = get_next_line(fd);

	//printf("Lectura: %s\n", lecture);
	//printf("linea: %s\n", line);
	//printf("linea2: %s\n", line2);
	printf("get_next_line es: %s\n", getnextline);
	
	getnextline  = get_next_line(fd);
	printf("get_next_line es: %s\n", getnextline);
    //free(lecture);
	//free(line2);
   //free(line);	// Liberar la memoria asignada

    return 0;
 
}
*/
