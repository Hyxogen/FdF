/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:56:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:31:34 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BUFFER_H
# define IMAGE_BUFFER_H

# include "color.h"
# include "window.h"
# include "math/vector2i.h"
# include "util/types.h"
# include <ft_stdbool.h>

typedef struct s_image_buffer {
	void		*m_mlx_handle;
	void		*m_image_handle;
	t_byte		*m_image_address;
	t_int32		m_image_width;
	t_int32		m_image_height;
	t_int32		m_line_width;
	t_int32		m_bit_per_pixel;
	t_int32		m_endian;
}	t_image_buffer;

t_image_buffer	*ib_create(void *mlx_handle, t_int32 width, t_int32 height);
void			ib_destroy(t_image_buffer *buffer, t_bool free_self);

void			ib_put_pixel(t_image_buffer *buffer,
					t_vector2i point, t_color color);
void			ib_clear(t_image_buffer *buffer);

t_bool			ib_put(t_image_buffer *buffer,
					t_window *window, t_vector2i point);
t_bool			ib_flush(t_image_buffer *buffer,
					t_window *window, t_vector2i point);

#endif
