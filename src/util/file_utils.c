/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   file_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:21:19 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/02/02 15:21:19 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "platform.h"
#include "file_utils.h"
#include "mem_utils.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef FILE_UTILS_BUFFER_SIZE
# define FILE_UTILS_BUFFER_SIZE 1024
#endif

t_bool
	file_can_read(const char *name)
{
	t_int32	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	close(fd);
	return (TRUE);
}

t_bool
	file_tell_size(const char *file, t_size *file_size)
{
	t_size	read_size;
	char	buffer[FILE_UTILS_BUFFER_SIZE];
	t_int32	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	*file_size = 0;
	while (TRUE)
	{
		read_size = read(fd, &buffer, FILE_UTILS_BUFFER_SIZE);
		if (read_size < 0)
			return (FALSE);
		if (read_size == 0)
			break ;
		*file_size += read_size;
	}
	close(fd);
	return (TRUE);
}

t_bool
	file_readall(const char *file, char **out, t_size *file_size)
{
	t_int32	fd;
	char	*buffer;

	if (file_tell_size(file, file_size) == FALSE)
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	buffer = safe_malloc(sizeof(char) * *file_size);
	if (read(fd, buffer, *file_size) < 0)
	{
		free(buffer);
		return (FALSE);
	}
	*out = buffer;
	close(fd);
	return (TRUE);
}
