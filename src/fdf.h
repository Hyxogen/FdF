/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 07:54:56 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 07:55:19 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "gfx/window.h"
# include "gfx/image_buffer.h"
# include "map/map.h"

enum e_rendermode {
	rm_iso,
	rm_pers,
	rm_ortho
};

typedef struct s_fdf {
	void				*m_mlx_handle;
	t_image_buffer		*m_image_buffer;
	enum e_rendermode	m_render_mode;
	t_window			*m_main_window;
	t_map				*m_loaded_map;
}	t_fdf;

void	fdf_instance_init(t_fdf *fdf,
			void *mlx_handle, t_window *main_window, t_map *loaded_map);
t_fdf	*fdf_instance_create(void);
void	fdf_instance_destroy(t_fdf *instance);

t_int32	fdf_loop(void	*instance_ptr);
#endif
