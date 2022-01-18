/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assert.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:53:34 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/18 15:56:28 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"
#include <stdlib.h>
#ifdef FDF_DEBUG
# include <signal.h>
#endif

#ifdef FDF_DEBUG

void
	debug_assert(t_bool assertion)
{
	if (!assertion)
		raise(SIGTRAP);
}

#else

void
	debug_assert(t_bool assertion)
{
	(void)assertion;
}
#endif

void
	always_assert(t_bool assertion)
{
	if (!assertion)
		exit(EXIT_FAILURE);
}
