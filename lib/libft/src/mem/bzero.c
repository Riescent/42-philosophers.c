/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfries <vfries@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:59:28 by vfries            #+#    #+#             */
/*   Updated: 2023/01/09 01:03:08 by vfries           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
