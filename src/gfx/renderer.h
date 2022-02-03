/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:07:37 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/03 12:54:54 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "image_buffer.h"
# include "math/vector2i.h"
# include "math/vector2f.h"
# include "math/vector4f.h"
# include "math/matrix4f.h"
# include "map/map.h"

void		render_line_direct(t_image_buffer *buffer,
				t_vector2i start, t_vector2i end, t_color color);

void		render_line(t_image_buffer *buffer,
				t_vector4f start, t_vector4f end, t_color color);

void		_render_quads_part(t_image_buffer *buffer,
				t_vector4f from, t_vector4f to, t_color color);
void		render_quads(t_image_buffer *buffer,
				t_vector2i dimensions, const t_vector4f *points, t_color color);
void		render_quads_ndc(t_image_buffer *buffer,
				t_vector2i dimensions,
				const t_vector2f *ndc_points, t_color color);
void		render_map_fit(t_image_buffer *buffer,
				const t_matrix4f *transformation,
				const t_map *map, t_color color);
void		render_map(t_image_buffer *buffer,
				const t_matrix4f *transformation,
				const t_map *map, t_color color);

t_bool		_clip_line(t_vector4f *start, t_vector4f *end, t_color *color);
void		_normalize_vector(t_vector4f *out,
				const t_vector4f *list, t_size count);
void		_ndc_to_window(t_image_buffer *buffer,
				t_vector2i *out, t_vector2f *ndc_points, t_size n);
#endif
