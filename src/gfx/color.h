/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:28:08 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:53:27 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "../util/types.h"

# define COLOR_ALPHA_OFFSET 24
# define COLOR_RED_OFFSET 16
# define COLOR_GREEN_OFFSET 8
# define COLOR_BLUE_OFFSET 0

# define COLOR_ALPHA_MASK	0xff000000
# define COLOR_RED_MASK		0x00ff0000
# define COLOR_GREEN_MASK	0x0000ff00
# define COLOR_BLUE_MASK	0x000000ff

typedef t_int32	t_color;

t_color	color_encode(t_byte alpha, t_byte red, t_byte green, t_byte blue);

t_color	color_white(void);
t_color	color_red(void);
t_color	color_green(void);
t_color	color_blue(void);

#endif