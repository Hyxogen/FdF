/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 13:07:37 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 13:08:53 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "image_buffer.h"

void	render_line(t_image_buffer *buffer, t_vector2 start, t_vector2 end);

#endif
