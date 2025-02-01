/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olachhab <olachhab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:44:50 by olachhab          #+#    #+#             */
/*   Updated: 2025/01/31 11:49:07 by olachhab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy(new_str + len1, s2, len2);
	new_str[len1 + len2] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *src)
{
	char	*reserve;
	size_t	len;
	size_t	i;

	len = ft_strlen(src);
	reserve = (char *)malloc((len + 1) * sizeof(char));
	if (reserve == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		reserve[i] = src[i];
		i++;
	}
	reserve[len] = '\0';
	return (reserve);
}

char	*ft_strchr(const char *s, int c)
{
	char		target;
	const char	*ptr;

	if (!s)
		return (NULL);
	target = (char)c;
	ptr = s;
	while (*ptr)
	{
		if (*ptr == target)
		{
			return ((char *)ptr);
		}
		ptr++;
	}
	if (*ptr == target)
	{
		return ((char *)ptr);
	}
	return (NULL);
}
