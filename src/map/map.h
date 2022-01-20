/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/20 09:04:43 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 09:12:13 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <math/vector3f.h>
# include <math/vector4f.h>
# include <ft_stdbool.h>

typedef struct s_map {
	t_int32		m_width;
	t_int32		m_height;
	t_vector4f	*m_vertices;
}	t_map;

t_bool	map_init(t_map *map,
			t_int32 width, t_int32 height, t_vector3f *vertices);
t_map	*map_create(t_int32 width, t_int32 height, t_vector3f *vertices);)

#endif
