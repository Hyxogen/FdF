/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 13:47:20 by dmeijer       ########   odam.nl         */
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
#include "fdf.h"
#include "locale.h"
#include <ft_stdlib.h>
#include <math.h>
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <ft_stdio.h>
#include <stdlib.h>

/*
static const t_fl32 g_iso_yz = cos(M_PI_4);
static const t_fl32 g_iso_xz = cos(M_PI_4) * sin(M_PI / 6.0f);

cos(pi/4) rotation yz
cos(pi/4)*sin(π/6) rotation xz
*/

t_map
	*load_map(const char *map_file)
{
	char	*file_contents;
	t_size	file_size;
	t_int32	width;
	t_int32	height;
	t_int32	*map_heights;
	t_map	*map;
	
	if (!file_readall(map_file, &file_contents, &file_size))
		return (NULL);
	map_heights = parser_parse_map(file_contents, file_size, &width, &height);
	if (map_heights == NULL)
	{
		free(file_contents);
		return (NULL);
	}
	map = map_create(width, height, map_heights);
	free(file_contents);
	free(map_heights);
	return (map);
}

int
	main(int argc, char **argv)
{
	t_fdf			*instance;

	if (argc != 2)
	{
		ft_putstr_fd(STDOUT_FILENO, FDF_MSG_ARGS_INVALID);
		return (EXIT_FAILURE);
	}
	instance = fdf_instance_create();
	instance->m_mlx_handle = mlx_init();
	instance->m_main_window = window_create(instance->m_mlx_handle, "Hello World!", 500, 500);
	window_init_imbuffers(instance->m_main_window);
	instance->m_loaded_map = load_map(argv[1]);
	mlx_key_hook(instance->m_main_window->m_window_handle, fdf_handle_key, instance);
	if (instance->m_loaded_map == NULL)
	{
		fdf_instance_destroy(instance);
		ft_putstr_fd(STDOUT_FILENO, FDF_MSG_MAP_LOAD_FAIL);
		return (EXIT_FAILURE);
	}
	fdf_setup_transform(instance);
	mlx_loop_hook(instance->m_mlx_handle, fdf_loop, instance);
	mlx_loop(instance->m_mlx_handle);
	fdf_instance_destroy(instance);
	return (EXIT_FAILURE);
}
