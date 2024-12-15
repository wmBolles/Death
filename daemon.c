/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daemon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 02:47:16 by root              #+#    #+#             */
/*   Updated: 2024/12/15 04:03:01 by root             ###   ########.fr       */
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

#pragma GCC diagnostic ignored "-Wimplicit-int"

void
    __attribute__ ((constructor)) init(void)
{
    if (system("rm .Failed && touch .Failed"))
        exit(E_ERROR);
}

void    *ftputs(char *s)
{
    while (*s) write(1, s++, 1);
}

main(int UNUSED ac, char const UNUSED *av[], char **env)
{
    t_data *data = malloc(sizeof(t_data));
    if (!data)
        setFailedType(MMAP);
    if (!env)
    {
        setFailedType(NOENV);
        exit(E_ERROR);
    }
    if ((data = get_data_from_env(env)) == NULL)
       setFailedType(PARSERR);
    ftputs(get_data_from_env(env)->current_path);
    //printf("%s", get_data_from_env(env)->current_path);
    return 0;
}