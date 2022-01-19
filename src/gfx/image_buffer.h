/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:56:25 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:59:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_BUFFER_H
# define IMAGE_BUFFER_H

# include "color.h"
# include "math/vector2f.h"

typedef struct s_image_buffer {
}	t_image_buffer;

void	ib_put_pixel(t_vector2f point, t_color color);

#endif
