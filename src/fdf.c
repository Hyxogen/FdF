/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 10:11:50 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "math/vector2i.h"
#define __USE_MISC
#define _ISO99_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include "gfx/window.h"
#include "gfx/image_buffer.h"
#include "gfx/renderer.h"
#include "util/assert.h"
#include "parser/map_parser.h"
#include "math/matrix4f.h"
#include "map/map.h"
#include "util/mem_utils.h"
#include "util/file_utils.h"
#include <ft_string.h>
#include <ft_stdlib.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/*
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
	{-50, 0, 50, 1}, {0, 0, 50, 1}, {50, 0, 50, 1},
	{-50, 0, 0, 1}, {0, -50, 0, 1}, {50, 0, 0, 1},
	{-50, 0, -50, 1}, {0, 0, -50, 1}, {50, 0, -50, 1}
};

t_ortho_settings g_projection = {
	-1.0f, 1.0f,
	0.0f, 500.0f,
	0.0f, 500.0f
};
*/

t_int32	g_map[] = {
	0, 0, 0,
	0, 50, 0,
	0, 0, 0
};

t_map	*g_loaded_map;

/*
static const t_fl32 g_iso_yz = cos(M_PI_4);
static const t_fl32 g_iso_xz = cos(M_PI_4) * sin(M_PI / 6.0f);

cos(pi/4) rotation yz
cos(pi/4)*sin(π/6) rotation xz
*/

void
	norm_trans(t_vector4f *vertices, t_int32 count)
{
	t_matrix4f scale;
	t_vector4f *result;
	t_int32	index;
	t_fl32	largest;

	largest = vertices->m_x;
	result = safe_malloc(sizeof(t_vector4f) * count);
	index = 0;
	while (index < count)
	{
		if (ft_abs(vertices[index].m_x) > largest)
			largest = ft_abs(vertices[index].m_x);
		if (ft_abs(vertices[index].m_y) > largest)
			largest = ft_abs(vertices[index].m_y);
		index++;
	}
	scale = matrix4f_usscale(1.0f / largest);
	matrix4f_mulva(result, &scale, vertices, count);
	ft_memcpy(vertices, result, sizeof(t_vector4f) * count);
	free(result);
}

int
	temp_loop(void *param)
{
	static t_image_buffer	*buffer;
	static t_fl32				a;
	t_window				*window;
	t_matrix4f				trans;
	t_matrix4f				effect;
	t_matrix4f				rot;
	t_vector4f				*transformed;
	t_vector2f				*ndc_points;
	t_vector4f				*map_vertices;
	t_int32					width, height;

	width = g_loaded_map->m_width;
	height = g_loaded_map->m_height;
	map_vertices = g_loaded_map->m_vertices;
	rot = matrix4f_rotation(vector3f_normalize(vector3f(1.0f, 1.0f, 0.0f)), a);
	window = param;
	if (!buffer)
		buffer = ib_create(window->m_mlx_handle, window->m_width, window->m_height);
	ib_clear(buffer);
	trans = matrix4f_identity();
	effect = matrix4f_mulm(&trans, &rot);

	transformed = safe_malloc(sizeof(t_vector4f) * width * height);
	ndc_points = safe_malloc(sizeof(t_vector2f) * width * height);
	matrix4f_mulva(transformed, &effect, map_vertices, width * height);
	norm_trans(transformed, width * height);
	vector2f_convert4f(ndc_points, transformed, width * height);
	render_quads_ndc(buffer, vector2i(width, height), ndc_points, color_white());	
/*	render_quads(buffer, vector2i(width, height), transformed, color_white());*/
	ib_put(buffer, window, vector2i_zero());
	(void)a;
	a += 0.001f;
	free(ndc_points);
	free(transformed);
	return (FALSE);
}
void	
	load_map(int argc, char **argv)
{
	char	*file_contents;
	t_size	file_size;
	t_int32	width;
	t_int32	height;
	t_int32	*heights;

	(void)argc;
	file_readall(argv[1], &file_contents, &file_size);
	heights = parser_parse_map(file_contents, file_size, &width, &height);
	g_loaded_map = map_create(width, height, heights);
	free(file_contents);
	free(heights);
}


int
	main(int argc, char **argv)
{
	void			*mlx_handle;
	t_window		*window;
	t_image_buffer	*buffer;
	t_vector2i		start;
	t_vector2i		end;

	load_map(argc, argv);
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
