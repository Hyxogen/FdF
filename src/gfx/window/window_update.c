/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window_update.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:13:16 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:13:56 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../window.h"
#include <mlx.h>

void
	window_update(t_window *window)
{
	mlx_loop(window->m_mlx_handle);
}
