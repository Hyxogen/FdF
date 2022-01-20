/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 12:51:58 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfx/window.h"
#include "gfx/image_buffer.h"
#include "gfx/renderer.h"
#include "util/assert.h"
#include "mlx.h"

t_vector4f	g_map[] =
{
	{250, 250, 0, 0}, {300, 250, 0 ,0}, {350, 250, 0, 0},
	{250, 300, 0 ,0}, {300, 300, 0, 0}, {350, 300, 0, 0},
	{250, 350, 0 ,0}, {300, 350, 0, 0}, {350, 350, 0, 0}
};

int
	main(void)
{
	void			*mlx_handle;
	t_window		*window;
	t_image_buffer	*buffer;
	t_vector2i		start;
	t_vector2i		end;

	mlx_handle = mlx_init();
	window = window_create(mlx_handle, "Hello World", 500, 500);
	debug_assert((buffer = ib_create(mlx_handle, 500, 500)) != NULL);
	start.m_x = 250;
	start.m_y = 250;
	end.m_x = 499;
	end.m_y = 499;
	ib_clear(buffer);
	render_wireframe(buffer, vector2i(3, 3), g_map, color_red());
	ib_put(buffer, window, vector2i_zero());
	while (TRUE)
		window_update(window);
	window_destroy(window, TRUE);
	return (0);
}
