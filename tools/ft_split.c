/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:33:26 by root              #+#    #+#             */
/*   Updated: 2024/12/15 03:33:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The MIT License (MIT)

// Copyright (c) 2024 THEF

//  Permission is hereby granted, free of charge, to any person obtaining a
//  copy of this software and associated documentation files (the "Software"),
//  to deal in the Software without restriction, including without limitation
//  the rights to use, copy, modify, merge, publish, distribute, sublicense,
//  and/or sell copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//  DEALINGS IN THE SOFTWARE.

#include "daemon.h"

static int	word_count(char *str, char c)
{
	int		count;
	int		index;

	count = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] != c)
		{
			count++;
			while (str[index] && str[index] != c)
				index++;
		}
		else
			index++;
	}
	return (count);
}

static void	*ft_leak(char **memory, int i)
{
	while (i >= 0)
	{
		free(memory[i]);
		i--;
	}
	free(memory);
	return (NULL);
}

static char	*wb_cstrdup(char *str, char c, int *p)
{
	char	*allocation;
	int		index;
	int		len;

	len = 0;
	(*p)++;
	while (str[len] != c && str[len])
		len++;
	allocation = malloc(len + 1);
	if (!allocation)
		return (NULL);
	index = 0;
	while (index < len)
	{
		allocation[index] = str[index];
		index++;
	}
	allocation[index] = '\0';
	return (allocation);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char		*str;
	int			index;

	str = (char *)s;
	if (!str)
		return (NULL);
	split = malloc((sizeof(char *) * (word_count(str, c) + 1)));
	if (!split)
		return (NULL);
	index = 0;
	while (*str)
	{
		if (*str != c)
		{
			split[index - 1] = wb_cstrdup(str, c, &index);
			if (split[index - 1] == NULL)
				return (ft_leak(split, index - 1));
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (split[index] = NULL, split);
}
