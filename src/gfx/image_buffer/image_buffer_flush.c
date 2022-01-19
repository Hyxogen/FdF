/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_flush.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:11:58 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:31:34 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../image_buffer.h"
#include <mlx.h>
#include <ft_stdbool.h>

t_bool
	ib_flush(t_image_buffer *buffer, t_window *window, t_vector2i point)
{
	t_bool	success;

	success = ib_put(buffer, window, point);
	ib_clear(buffer);
	return (success);
}
