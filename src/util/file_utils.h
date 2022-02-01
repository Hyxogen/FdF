#ifndef FILE_UTILS_H
# define FILE_UTILS_H

# include <ft_stdbool.h>
# include "types.h"

t_bool	file_exits(const char *file);

t_bool	file_tell_size(const char *file, t_size *total_size);

t_bool	file_readall(const char *file, char **out, t_size *file_size);

#endif
