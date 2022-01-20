/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector2i.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:58:23 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/20 08:39:45 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2I_H
# define VECTOR2I_H

# include "../util/types.h"

typedef struct s_vector2i {
	t_int32	m_x;
	t_int32	m_y;
}	t_vector2i;

t_vector2i	vector2i_zero(void);

#endif
