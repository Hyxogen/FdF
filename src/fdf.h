/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:54:56 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:46:23 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "gfx/window.h"
# include "gfx/image_buffer.h"
# include "map/map.h"
# include "transform/transform.h"

typedef struct s_fdf {
	void				*m_mlx_handle;
	t_image_buffer		*m_image_buffer;
	t_window			*m_main_window;
	t_map				*m_loaded_map;
	t_transform			m_map_transform;
}	t_fdf;

void	fdf_instance_init(t_fdf *fdf,
			void *mlx_handle, t_window *main_window, t_map *loaded_map);
t_fdf	*fdf_instance_create(void);
void	fdf_instance_destroy(t_fdf *instance);

t_bool	fdf_init(t_fdf *instance, const char *map_file);
t_bool	fdf_start(t_fdf *instance);

t_int32	fdf_handle_key(t_int32 keycode, t_fdf *instance);
t_int32	fdf_loop(void	*instance_ptr);

void	fdf_setup_transform(t_fdf *instance);
void	fdf_quit(t_fdf *instance);
#endif
