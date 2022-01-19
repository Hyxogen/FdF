/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image_buffer_destroy.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 12:49:15 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 12:53:26 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "../image_buffer.h"
# include <ft_stdbool.h>
# include <stdlib.h>

t_bool
	_ib_destroy_handle(t_image_buffer *buffer)
{
	mlx_destroy_image(buffer->m_mlx_handle, ->m_image_handle);
	return (TRUE);
}

void
	ib_destroy(t_image_buffer *buffer, t_bool free_self)
{
	_ib_destroy_handle(buffer);
	if (free_self)
		free(buffer);
}
