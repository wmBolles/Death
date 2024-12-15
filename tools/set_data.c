/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:08:08 by root              #+#    #+#             */
/*   Updated: 2024/12/15 03:57:35 by root             ###   ########.fr       */
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

void *set_data_in_heap(char *dst, char *envi)
{
    short   size;
    short   index;

    while (envi[index])
    {
        if (envi[index == '='])
            while (envi[size]) size++;
        index++;
    }
    char    **splits = ft_split(envi, '=');
    dst = malloc(size + 1);
    if (!dst) return NULL;
    strcpy(dst, envi);
    return (dst);  
}

t_data
    *get_data_from_env(char **env)
{
    t_data  data;
    short   check;
    
    for (int i = 0; i < 27; i++)
    {
        if (env[i] == NULL)
            check = -FAILURE;
    }
    if (check == -FAILURE) {
        setFailedType(VARP); exit(VARP); }
    data.current_path = NULL;
    for (int i = 0; i < 27; i++)
    {
        if (!strcmp("PATH", env[i]))
            set_data_in_heap(data.current_path , env[i]);
    }
    return (SUCCESS);
}