/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failedtype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 03:15:30 by root              #+#    #+#             */
/*   Updated: 2024/12/15 04:00:28 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "daemon.h"

void
    setFailedType(short errortype)
{
    if (errortype == NOENV)
        system("echo NoEnvData >> .Failed");
    else if (errortype == PARSERR)
        system("echo ParsingError >> .Failed");
    else if (errortype == VARP)
        system("echo ErrorInEnvVar > .Failed");
    else if (errortype = MMAP) system("echo MMAP_ERR > .Failed");
}  