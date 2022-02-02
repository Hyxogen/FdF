/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_init.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:30:14 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 16:04:09 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "locale.h"
#include "fdf.h"
#include "parser/map_parser.h"
#include "util/file_utils.h"
#include <stdlib.h>
#include <ft_stdio.h>
#include <unistd.h>

void
	_fdf_init_gfx(t_fdf *instance)
{
	instance->m_mlx_handle = mlx_init();
	instance->m_main_window = window_create(instance->m_mlx_handle,
			FDF_WINDOW_NAME, 500, 500);
	window_init_imbuffers(instance->m_main_window);
}

void
	_fdf_setup_hooks(t_fdf *instance)
{
	mlx_key_hook(instance->m_main_window->m_window_handle,
		fdf_handle_key, instance);
	mlx_loop_hook(instance->m_mlx_handle, fdf_loop, instance);
}

t_int32
	*_fdf_load_height_map(const char *map_file, t_int32 *width, t_int32 *height)
{
	char	*file_contents;
	t_size	file_size;
	t_int32	*height_map;

	if (!file_readall(map_file, &file_contents, &file_size))
		return (NULL);
	height_map = parser_parse_map(file_contents, file_size, width, height);
	free(file_contents);
	return (height_map);
}

t_map
	*_fdf_load_map(const char *map_file)
{
	t_int32	width;
	t_int32	height;
	t_int32	*height_map;
	t_map	*map;

	height_map = _fdf_load_height_map(map_file, &width, &height);
	if (height_map == NULL)
		return (NULL);
	map = map_create(width, height, height_map);
	free(height_map);
	return (map);
}

t_bool
	fdf_init(t_fdf *instance, const char *map_file)
{
	_fdf_init_gfx(instance);
	instance->m_loaded_map = _fdf_load_map(map_file);
	if (instance->m_loaded_map == NULL)
	{
		fdf_instance_destroy(instance);
		ft_putstr_fd(STDERR_FILENO, FDF_MSG_MAP_LOAD_FAIL);
		return (FALSE);
	}
	fdf_setup_transform(instance);
	_fdf_setup_hooks(instance);
	return (TRUE);
}
