/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   safe_malloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:48:38 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 15:58:53 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mem_utils.h"
#include "assert.h"
#include <stdlib.h>

void
	*safe_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	always_assert(ret != NULL);
	return (ret);
}
