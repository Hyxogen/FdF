/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:00:42 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:33:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "../util/types.h"
# include <ft_stdbool.h>

struct s_image_buffer;

typedef struct s_window {
	t_int32			m_width;
	t_int32			m_height;
	char			*m_title;
	void			*m_window_handle;
	void			*m_mlx_handle;
	struct s_image_buffer	*m_imbuffer_front;
}	t_window;

t_bool		_window_init(t_window *window, char *title,
				t_int32 width, t_int32 height);

/*MALLOC SAFE*/
t_window	*window_create(void *mlx, char *title,
				t_int32 width, t_int32 height);
void		window_destroy(t_window *window, t_bool free_self);

void		window_update(t_window *window);

t_bool		window_init_imbuffers(t_window *window);
#endif
