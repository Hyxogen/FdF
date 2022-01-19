/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_encode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:38:19 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 09:46:12 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../color.h"

t_color
	_color_get_alpha_part(t_byte alpha)
{
	return (((t_color) alpha) << COLOR_ALPHA_OFFSET);
}

t_color
	_color_get_red_part(t_byte red)
{
	return (((t_color) red) << COLOR_RED_OFFSET);
}

t_color
	_color_get_green_part(t_byte green)
{
	return (((t_color) green) << COLOR_GREEN_OFFSET);
}

t_color
	_color_get_blue_part(t_byte blue)
{
	return (((t_color) blue) << COLOR_BLUE_OFFSET);
}

t_color
	color_encode(t_byte alpha, t_byte red, t_byte green, t_byte blue)
{
	t_color	result;

	result = 0;
	result |= _color_get_alpha_part(alpha);
	result |= _color_get_red_part(red);
	result |= _color_get_green_part(green);
	result |= _color_get_blue_part(blue);
	return (result);
}
