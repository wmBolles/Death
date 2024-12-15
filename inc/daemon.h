/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:41:36 by root              #+#    #+#             */
/*   Updated: 2024/12/15 03:59:45 by root             ###   ########.fr       */
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

# pragma once
# pragma GCC diagnostic push

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>

# define UNUSED __attribute__ ((unused))

enum    e_macros
{
    SUCCESS = 0b00,
    FAILURE = 0b001,
    E_ERROR = -FAILURE,
    NOENV   = -0xfa,
    PARSERR = -0Xab,
    VARP    = -0X4F,
    MMAP    = -0XFF
};

typedef struct s_data
{
    char        *current_path;
    char        *USER;
    char        *secure_path;
    short       shlevel;
}   t_data;

t_data
    *get_data_from_env(char **env);
void
    setFailedType(short errortype);
char
    **ft_split(char const *s, char c);

#pragma GCC diagnostic pop