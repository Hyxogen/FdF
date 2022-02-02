/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_quit.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 08:11:00 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 09:54:57 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void
	fdf_quit(t_fdf *instance)
{
	fdf_instance_destroy(instance);
	exit(EXIT_SUCCESS);
}
