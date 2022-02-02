/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf_key_handler.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 08:00:11 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:22:34 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "util/types.h"
#include "util/keycodes.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

void
	fdf_move_map(t_fdf *instance, t_vector3f vector)
{
	t_matrix4f	translation;

	translation = matrix4f_translation(vector);
	instance->m_map_transform.m_translation
		= matrix4f_mulm(
			&instance->m_map_transform.m_translation,
			&translation);
}

void
	fdf_rotate_map(t_fdf *instance, t_vector3f angles)
{
	t_matrix4f	rotation;
	t_matrix4f	rot_part;

	rotation = matrix4f_rotation(vector3f(1.0f, 0.0f, 0.0f), angles.m_x);
	rot_part = matrix4f_rotation(vector3f(0.0f, 1.0f, 0.0f), angles.m_y);
	rotation = matrix4f_mulm(&rotation, &rot_part);
	rot_part = matrix4f_rotation(vector3f(0.0f, 0.0f, 1.0f), angles.m_z);
	rotation = matrix4f_mulm(&rotation, &rot_part);
	instance->m_map_transform.m_rotation
		= matrix4f_mulm(&instance->m_map_transform.m_rotation, &rotation);
}

void
	fdf_increase_scale(t_fdf *instance, t_vector3f scale)
{
	t_matrix4f	scale_mat;

	scale_mat = matrix4f_vscale(scale);
	instance->m_map_transform.m_scale
		= matrix4f_mulm(&instance->m_map_transform.m_scale, &scale_mat);
}

t_int32
	fdf_handle_key(t_int32 keycode, t_fdf *instance)
{
	printf("Keycode:%d\n", keycode);
	if (keycode == KEY_ESC)
		fdf_quit(instance);
	if (keycode == KEY_NUM5 || keycode == KEY_5)
		instance->m_render_mode = rm_pers;
	if (keycode == KEY_UP)
		fdf_move_map(instance, vector3f(0.0f, 0.25f, 0.0f));
	if (keycode == KEY_DOWN)
		fdf_move_map(instance, vector3f(0.0f, -0.25f, 0.0f));
	if (keycode == KEY_LEFT)
		fdf_move_map(instance, vector3f(-0.25f, 0.0f, 0.0f));
	if (keycode == KEY_RIGHT)
		fdf_move_map(instance, vector3f(0.25f, 0.0f, 0.0f));
	if (keycode == KEY_Q)
		fdf_increase_scale(instance, vector3f(1.1f, 1.1f, 1.1f));
	if (keycode == KEY_E)
		fdf_increase_scale(instance, vector3f(0.9f, 0.9f, 0.9f));
	if (keycode == KEY_Z)
		fdf_rotate_map(instance, vector3f(0.0f, 0.0f, M_PI / 10.0f));
	if (keycode == KEY_X)
		fdf_rotate_map(instance, vector3f(0.0f, 0.0f, -M_PI / 10.0f));
	return (FALSE);
}
