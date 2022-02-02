/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 15:34:26 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:44:42 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "locale.h"
#include <stdlib.h>
#include <unistd.h>
#include <ft_stdio.h>

int
	main(int argc, char **argv)
{
	t_bool			success;
	t_fdf			*instance;

	if (argc != 2)
	{
		ft_putstr_fd(STDERR_FILENO, FDF_MSG_ARGS_INVALID);
		return (EXIT_FAILURE);
	}
	instance = fdf_instance_create();
	if (!fdf_init(instance, argv[1]))
		return (EXIT_FAILURE);
	success = fdf_start(instance);
	fdf_instance_destroy(instance);
	if (success)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
