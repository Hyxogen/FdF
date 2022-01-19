/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 14:43:33 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfx/window.h"
#include "gfx/image_buffer.h"
#include "util/assert.h"
#include "mlx.h"

int
	main(void)
{
	void			*mlx_handle;
	t_window		*window;
	t_image_buffer	*buffer;
	t_vector2i		origin;
	int y;
	int x;

	mlx_handle = mlx_init();
	window = window_create(mlx_handle, "Hello World", 500, 500);
	debug_assert((buffer = ib_create(mlx_handle, 500, 500)) != NULL);
	origin.m_x = 0;
	origin.m_y = 0;
	for (y = 0; y < 500; y++)
	{
		for (x = 0; x < 500; x++)
			ib_put_pixel(buffer, x, y, color_red());
	}
	ib_put(buffer, window, origin);
	while (TRUE)
		window_update(window);
	window_destroy(window, TRUE);
	return (0);
}
