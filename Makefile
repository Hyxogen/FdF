TARGET				:= fdf 

DEPEND_DIR 			:= ./Dependencies
VENDOR_DIR 			:= ./Vendor
INT_DIR 			:= ./obj

LIBFT_DIR			:= $(DEPEND_DIR)/libft
LIBFT_LIB			:= $(LIBFT_DIR)/libft.a

MLX_DIR				:=
MLX_LIB				:=

OSX_MLX_DIR			:= $(VENDOR_DIR)/minilibx-osx
OSX_MLX_LIB			:= $(OSX_MLX_DIR)/libmlx_x86_64.a
LINUX_MLX_DIR		:= $(VENDOR_DIR)/minilibx-linux
LINUX_MLX_LIB		:= $(LINUX_MLX_DIR)/libmlx_Linux.a

ifndef config
	config := debug_osx
endif

ifeq ($(config), debug_linux)
	ALL_CFLAGS		+= $(DEBUG_CFLAGS)
	ALL_LINKFLAGS	+= $(DEBUG_LINKFLAGS)
	DEFINES			+= $(DEBUG_DEFINES)
	MLX_LIB			:= $(LINUX_MLX_LIB)
	MLX_DIR			:= $(LINUX_MLX_DIR)
else ifeq ($(config), release_linux)
	ALL_CFLAGS		+= $(RELEASE_CFLAGS)
	ALL_LINKFLAGS	+= $(RELEASE_LINKFLAGS)
	DEFINES			+= $(RELEASE_DEFINES)
	MLX_LIB			:= $(LINUX_MLX_LIB)
	MLX_DIR			:= $(LINUX_MLX_DIR)
else ifeq ($(config), distr_linux)
	ALL_CFLAGS		+= $(DISTR_CFLAGS)
	ALL_CFLAGS		+= $(DISTR_DEFINES)
	ALL_LINKFLAGS	+= $(DISTR_LINKFLAGS)
	MLX_LIB			:= $(LINUX_MLX_LIB)
	MLX_DIR			:= $(LINUX_MLX_DIR)
else ifeq ($(config), debug_osx)
	ALL_CFLAGS		+= $(DEBUG_CFLAGS)
	ALL_LINKFLAGS	+= $(DEBUG_LINKFLAGS)
	DEFINES			+= $(DEBUG_DEFINES)
	MLX_LIB			:= $(OSX_MLX_LIB)
	MLX_DIR			:= $(OSX_MLX_DIR)
else ifeq ($(config), release_osx)
	ALL_CFLAGS		+= $(RELEASE_CFLAGS)
	ALL_LINKFLAGS	+= $(RELEASE_LINKFLAGS)
	DEFINES			+= $(RELEASE_DEFINES)
	MLX_LIB			:= $(OSX_MLX_LIB)
	MLX_DIR			:= $(OSX_MLX_DIR)
else ifeq ($(config), distr_osx)
	ALL_CFLAGS		+= $(DISTR_CFLAGS)
	ALL_CFLAGS		+= $(DISTR_DEFINES)
	ALL_LINKFLAGS	+= $(DISTR_LINKFLAGS)
	MLX_LIB			:= $(OSX_MLX_LIB)
	MLX_DIR			:= $(OSX_MLX_DIR)
else
	$(error "Invalid config $(config)")
endif

SRC_DIR				:= ./src

SRC_FILES			:= fdf.c matrix4f_mulm.c matrix4f_mulv.c matrix4f_ortho.c \
						matrix4f_transpose.c matrix4f_transpose.c \
						window_destroy.c window_init.c safe_malloc.c \
						assert.c
OBJ_FILES			:= $(addprefix $(INT_DIR)/,$(SRC_FILES:%.c=%.o))

VPATH				:= $(SRC_DIR) $(SRC_DIR)/math $(SRC_DIR)/math/matrix4f \
						$(SRC_DIR)/gfx/window $(SRC_DIR)/util

DEFINES				:=
INCLUDE_DIRS		:= -I $(LIBFT_DIR)/include -I $(MLX_DIR)
LIBRARIES			:= $(LIBFT_LIB) $(MLX_LIB)

CC					:= clang
LINK_CMD			:= clang

ALL_CFLAGS			:= -std=c89 -Wall -Wextra -Werror -pedantic $(INCLUDE_DIRS)
ALL_LINKFLAGS		:= -framework OpenGL -framework AppKit

DEBUG_CFLAGS		:= -g -O0 -fsanitize=address
DEBUG_LINKFLAGS		:= -fsanitize=address -fsanitize=undefined
DEBUG_DEFINES		:= -DFDF_DEBUG

RELEASE_CFLAGS		:= -g -O2 -fsanitize=address
RELEASE_LINKFLAGS	:= -fsanitize=address -fsanitize=undefined
RELEASE_DEFINES		:= -DFDF_RELEASE

DISTR_CFLAGS		:= -Ofast -g0
DISTR_LINKFLAGS		:=
DISTR_DEFINES		:= -DFDF_DISTRIBUTION

SILENT		:= @
ifdef verbose
	SILENT	:=
endif

all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(LIBRARIES)
	$(SILENT)echo Linking $@
	$(SILENT)$(LINK_CMD) $(OBJ_FILES) $(LIBRARIES) $(ALL_LINKFLAGS) -o $@

$(INT_DIR)/%.o: %.c
	$(SILENT)echo $(notdir $<)
	$(SILENT)mkdir -p $(INT_DIR)
	$(SILENT)$(CC) $(ALL_CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(SILENT)${MAKE} -C $(LIBFT_DIR) -f Makefile config=distr

$(MLX_LIB):
	$(SILENT)(cd $(MLX_DIR) && ./configure)

clean:
	$(SILENT)echo Cleaning object files
	$(SILENT)rm -f $(OBJ_FILES)

fclean: clean
	$(SILENT)echo Cleaning $(TARGET)
	$(SILENT)rm -f $(TARGET)

re: fclean all
