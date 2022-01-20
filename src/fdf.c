/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 15:27:43 by dmeijer       ########   odam.nl         */
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
#include "math.h"
#include "mlx.h"

t_vector4f	g_map[] =
{
	{250, 250, 250, 0}, {300, 250, 250 ,0}, {350, 250, 250, 0},
	{250, 250, 300 ,0}, {300, 250, 300, 0}, {350, 250, 300, 0},
	{250, 250, 350 ,0}, {300, 250, 350, 0}, {350, 250, 350, 0}
};

void
	do_test(t_image_buffer *buffer)
{
	t_ortho_settings	settings;
	t_matrix4f			proj;
	t_matrix4f			rot;
	t_vector4f			*transformed;
	t_vector4f			*transformed2;

	settings.m_far = 10.0f;
	settings.m_near = 1.0f;
	settings.m_left = 5.0f;
	settings.m_right = 5.0f;
	settings.m_top = 5.0f;
	settings.m_bottom = 5.0f;
	transformed = safe_malloc(sizeof(t_vector4f) * 3 * 3);
	transformed2 = safe_malloc(sizeof(t_vector4f) * 3 * 3);
	proj = matrix4f_ortho(&settings);
	rot = matrix4f_rotation(vector3f(1, 0, 0), M_1_PI / 2.0f);
	matrix4f_mulva(transformed, &rot, g_map, 3 * 3);
	render_quads(buffer, vector2i(3, 3), transformed, color_red());
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
	do_test(buffer);
	ib_put(buffer, window, vector2i_zero());
	while (TRUE)
		window_update(window);
	window_destroy(window, TRUE);
	return (0);
}
