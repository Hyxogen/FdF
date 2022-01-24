/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 10:03:16 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "math/vector2i.h"
#define __USE_MISC
#include <stdio.h>
#include "gfx/window.h"
#include "gfx/image_buffer.h"
#include "gfx/renderer.h"
#include "util/assert.h"
#include "math/matrix4f.h"
#include "map/map.h"
#include "util/mem_utils.h"
#include <ft_string.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_vector4f	g_map[] =
{
	{-50, -50, 0, 1}, {0, -50, 0, 1}, {50, -50, 0, 1},
	{-50, 0,   0, 1}, {0, 0,   0, 1}, {50, 0,   0, 1},
	{-50, 50,  0, 1}, {0, 50,  0, 1}, {50, 50,  0, 1}
};

t_vector4f	g_map2[] =
{
	{0, 50, 250,  1}, {50, 50, 250,  1}, {100, 50, 250,  1},
	{0, 100, 300 ,1}, {50, 100, 300, 1}, {100, 100, 300, 1},
	{0, 150, 350 ,1}, {50, 150, 350, 1}, {100, 150, 350, 1}
};

t_vector4f g_cube[] =
{
	{-50, -50, 0, 1}, {0, -50, 0, 1}, {50, -50, 0, 1},
	{-50, 0, 0, 1}, {0, 0, 50, 1}, {50, 0, 0, 1},
	{-50, 50, 0, 1}, {0, 50, 0, 1}, {50, 50, 0, 1}
};

t_ortho_settings g_projection = {
	-1.0f, 1.0f,
	0.0f, 500.0f,
	0.0f, 500.0f
};

/*
static const t_fl32 g_iso_yz = cos(M_PI_4);
static const t_fl32 g_iso_xz = cos(M_PI_4) * sin(M_PI / 6.0f);

cos(pi/4) rotation yz
cos(pi/4)*sin(π/6) rotation xz
*/
int
	temp_loop(void *param)
{
	static t_image_buffer 	*buffer;
	static float 		a;
	t_window		*window;
	t_matrix4f		trans;
	t_matrix4f 		effect;
	t_matrix4f		proj;
	t_matrix4f 		rotxz;
	t_matrix4f		rotyz;
	t_matrix4f		rot;
	t_vector4f		*transformed;
	t_vector2f		*ndc_points;

	rotxz = matrix4f_rotation(vector3f_normalize(vector3f(0.0f, 1.0f, 0.0f)), M_PI_4);
	rotyz = matrix4f_rotation(vector3f_normalize(vector3f(1.0f, 0.0f, 0.0f)), 0.5235988f);
	rot = matrix4f_mulm(&rotxz, &rotyz);
	/*rot = matrix4f_rotation(vector3f_normalize(vector3f(-cos(M_PI_4), 0.0f, -cos(M_PI_4) * sin(M_PI / 6.0f))), a);*/
	proj = matrix4f_ortho(&g_projection);
	window = param;
	if (!buffer)
		buffer = ib_create(window->m_mlx_handle, window->m_width, window->m_height);
	ib_clear(buffer);
	trans = matrix4f_translation(vector3f(250.0f, 250.0f, 0.0f));
	effect = matrix4f_mulm(&trans, &rot);
	/*effect = matrix4f_mulm(&proj, &effect);*/

	transformed = safe_malloc(sizeof(t_vector4f) * 3 * 3);
	ndc_points = safe_malloc(sizeof(t_vector2f) * 3 * 3);
	matrix4f_mulva(transformed, &effect, g_cube, 3 * 3);
	vector2f_convert4f(ndc_points, transformed, 3 * 3);
	render_quads(buffer, vector2i(3, 3), transformed, color_white());
	/*render_quads_ndc(buffer, vector2i(3, 3), ndc_points, color_red());*/
	ib_put(buffer, window, vector2i_zero());
	a += 0.01f;
	free(ndc_points);
	free(transformed);
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
	ib_put(buffer, window, vector2i_zero());
	mlx_loop_hook(mlx_handle, temp_loop, window);
	mlx_loop(mlx_handle);
	window_destroy(window, TRUE);
	return (0);
}
