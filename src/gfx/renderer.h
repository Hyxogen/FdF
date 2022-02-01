/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:07:37 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 08:20:10 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "image_buffer.h"
# include "math/vector2i.h"
# include "math/vector2f.h"
# include "math/vector4f.h"
# include "map/map.h"

void	render_line(t_image_buffer *buffer,
			t_vector2i start, t_vector2i end, t_color color);

void	_render_quads_part(t_image_buffer *buffer,
			t_vector4f from, t_vector4f to, t_color color);
void	render_quads(t_image_buffer *buffer,
			t_vector2i dimensions, const t_vector4f *points, t_color color);
void	render_quads_ndc(t_image_buffer *buffer,
			t_vector2i dimensions, const t_vector2f *ndc_points, t_color color);
#endif
