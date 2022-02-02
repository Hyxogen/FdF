/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_start.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:33:22 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:34:15 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bool
	fdf_start(t_fdf *instance)
{
	mlx_loop(instance->m_mlx_handle);
	return (FALSE);
}
