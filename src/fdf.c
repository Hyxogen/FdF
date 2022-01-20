/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 16:32:46 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "gfx/window.h"
#include "gfx/image_buffer.h"
#include "gfx/renderer.h"
#include "util/assert.h"
#include "math/matrix4f.h"
#include "map/map.h"
#include "util/mem_utils.h"
#include <ft_string.h>
#include "math.h"
#include "mlx.h"

t_vector4f	g_map[] =
{
	{0, 50, 250,  1}, {50, 50, 250,  1}, {100, 50, 250,  1},
	{0, 100, 300 ,1}, {50, 100, 300, 1}, {100, 100, 300, 1},
	{0, 150, 350 ,1}, {50, 150, 350, 1}, {100, 150, 350, 1}
};

int
	temp_loop(void *param)
{
	static t_fl32	a = 0.0f;
	t_window		*window;
	t_matrix4f		trans;
	t_matrix4f		rot;
	t_matrix4f		effect;
	t_vector4f		*transformed;
	t_vector3f		center;
	t_image_buffer	*buffer;

	center = vector3f(50, 100, 300);
	window = param;
	buffer = ib_create(window->m_mlx_handle, window->m_width, window->m_height);
	rot = matrix4f_rotation(vector3f(0, 0, 1), M_1_PI / 2.0f);
	trans = matrix4f_translation(vector3f_inverse(&center));
	
	effect = matrix4f_mulm(&trans, &rot);
	trans = matrix4f_translation(center);
	effect = matrix4f_mulm(&effect, &trans);


	transformed = safe_malloc(sizeof(t_vector4f) * 3 * 3);
	matrix4f_mulva(transformed, &effect, g_map, 3 * 3);
	render_quads(buffer, vector2i(3, 3), transformed, color_red());
	ib_flush(buffer, window, vector2i(0, 0));
	a += 0.1f;
	return (FALSE);
}

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
	/*render_quads(buffer, vector2i(3, 3), g_map, color_red());*/
	ib_put(buffer, window, vector2i_zero());
	mlx_loop_hook(mlx_handle, temp_loop, window);
	mlx_loop(mlx_handle);
	while (TRUE)
		window_update(window);
	window_destroy(window, TRUE);
	return (0);
}
