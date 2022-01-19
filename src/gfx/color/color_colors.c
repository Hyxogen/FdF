/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_colors.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/19 09:53:39 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/19 14:59:31 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../color.h"

t_color
	color_white(void)
{
	return (color_encode(0x00, 0xFF, 0xFF, 0xFF));
}

t_color
	color_red(void)
{
	return (color_encode(0x00, 0xFF, 0x00, 0x00));
}

t_color
	color_green(void)
{
	return (color_encode(0x00, 0x00, 0xFF, 0x00));
}

t_color
	color_blue(void)
{
	return (color_encode(0x00, 0x00, 0x00, 0xFF));
}
