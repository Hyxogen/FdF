/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_instance_destroy.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:56:04 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 07:56:05 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void
	fdf_instance_destroy(t_fdf *instance)
{
	window_destroy(instance->m_main_window, TRUE);
	map_destroy(instance->m_loaded_map);
}
