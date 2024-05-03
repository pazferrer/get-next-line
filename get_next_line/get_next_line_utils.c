/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pferrer- <pferrer-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:36:33 by pferrer-          #+#    #+#             */
/*   Updated: 2024/05/03 21:39:18 by pferrer-         ###   ########.fr       */
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
	{
		i++;
	}
	return (i);
}

char	*join_string(char *string1, char *string2)
{
	int		i;
	int		j;
	int		y;
	char	*joint;

	i = length_string(string1) + length_string(string2) + 1;
	printf("len del join: %d\n", i);
	joint = malloc(i * sizeof(char));
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

int	newline_search(char *lecture)
{
	int	i;

	i = 0;
	while (lecture[i] != '\n' && lecture[i])
		i++;
	if (lecture[i] == '\n')
		return (1);
	else 
		return (0);
}

/*
int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	l1;
	size_t	l2;
	size_t	i;

	i = 0;
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	s3 = malloc(l1 + l2 + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, l1);
	while (i <= l2)
	{
		s3[l1] = s2[i];
		i++;
		l1++;
	}
	return (s3);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (start > (unsigned int)ft_strlen(s))
	{
		ret = malloc(sizeof(char) * 1);
		if (ret == NULL)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	ret = malloc((sizeof(char) * (len + 1)));
	if (ret == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}*/
