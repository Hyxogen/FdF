/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_parse_map.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmeijer <dmeijer@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 10:14:36 by dmeijer       #+#    #+#                 */
/*   Updated: 2022/01/24 10:33:03 by dmeijer       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../map_parser.h"
#include "util/mem_utils.h"
#include <ft_string.h>
#include <ft_ctype.h>
#include <ft_stdbool.h>
#include <ft_stdlib.h>

t_bool
	_parser_is_valid_entry(int c)
{
	return (c == '-' || c == '+' || ft_isdigit(c));
}

t_int32
	_parser_get_width(const char *map_str, t_size len)
{
	while (len && _parser_is_valid_entry(*map_str))
	{
		map_str++;
		len--;
	}
	if (*map_str == '\0' || *map_str == '\n')
		return (0);
	while (len && *map_str == ' ')
	{
		map_str++;
		len--;
	}
	return (_parser_get_width(map_str, len) + 1);
}

t_int32
	_parser_get_height(const char *map_str, t_size len)
{
	char	*new_line;

	new_line = ft_memchr(map_str, '\n', len);
	if (new_line == NULL)
		return (len);
	return (new_line - map_str);
}

void
	_parser_fill(t_int32 *out, const char *map_str, t_size len)
{
	while (len)
	{
		*out = ft_atoi(map_str);
		while (_parser_is_valid_entry(*map_str))
		{
			map_str++;
			len--;
		}
		while (*map_str == ' ' || *map_str == '\n')
		{
			map_str++;
			len--;
		}
		out++;
	}
}

t_int32
	*parser_parse_map(const char *map_str,
		t_size len, t_int32 *width, t_int32 *height)
{
	t_int32	*heights;

	*width = _parser_get_width(map_str, len);
	*height = _parser_get_height(map_str, len);
	if (*width * *height == 0)
		return (NULL);
	heights = safe_malloc(sizeof(t_int32) * *width * *height);
	_parser_fill(heights, map_str, len);
	return (heights);
}
