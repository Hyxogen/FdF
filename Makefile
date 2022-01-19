TARGET						:= fdf 

DEPEND_DIR 					:= ./Dependencies
VENDOR_DIR 					:= ./Vendor
INT_DIR 					:= ./obj

LIBFT_DIR					:= $(DEPEND_DIR)/libft
LIBFT_LIB					:= $(LIBFT_DIR)/libft.a

MLX_DIR						:=
MLX_LIB						:=

OSX_MLX_DIR					:= $(VENDOR_DIR)/minilibx-macos
OSX_MLX_LIB					:= $(OSX_MLX_DIR)/libmlx.a
LINUX_MLX_DIR				:= $(VENDOR_DIR)/minilibx-linux
LINUX_MLX_LIB				:= $(LINUX_MLX_DIR)/libmlx_Linux.a

DEPENDENCIES				:= $(LIBFT_LIB)

SRC_DIR						:= ./src

SRC_FILES					:= fdf.c matrix4f_mulm.c matrix4f_mulv.c matrix4f_ortho.c \
								matrix4f_transpose.c matrix4f_transpose.c \
								window_destroy.c window_init.c safe_malloc.c \
								assert.c
OBJ_FILES					:= $(addprefix $(INT_DIR)/,$(SRC_FILES:%.c=%.o))

VPATH						:= $(SRC_DIR) $(SRC_DIR)/math $(SRC_DIR)/math/matrix4f \
								$(SRC_DIR)/gfx/window $(SRC_DIR)/util

DEFINES						:=
INCLUDE_DIRS				:= -I $(LIBFT_DIR)/include -I $(MLX_DIR)
LIBRARIES					:= $(LIBFT_LIB) $(MLX_LIB) This is an error check

CC							:= clang
LINK_CMD					:= clang

ALL_CFLAGS					:= -std=c89 -Wall -Wextra -Werror -pedantic $(INCLUDE_DIRS)
ALL_LINKFLAGS				:= -L$(LIBFT_DIR) -lft

OSX_ALWAYS_LINKFLAGS		:= -L$(OSX_MLX_DIR) -lmlx -framework OpenGL -framework AppKit
OSX_ALWAYS_CFLAGS			:= -I$(OSX_MLX_DIR)
OSX_ALWAYS_DEFINES			:= $(OSX_DEBUG_DEFINES)
OSX_DEBUG_LINKFLAGS			:= -fsanitize=address
OSX_RELEASE_LINKSFLAGS		:= -fsanitize=address
OSX_DISTR_LINKSFLAGS		:=

#TODO fill this one out
LINUX_ALWAYS_LINKFLAGS		:= -L$(LINUX_MLX_DIR) -lmlx -X11
LINUX_ALWAYS_CFLAGS			:= -I$(LINUX_MLX_DIR)
LINUX_ALWAYS_DEFINES		:= -DFDF_PLATFORM_LINUX
LINUX_DEBUG_LINKFLAGS		:= -fsanitize=address
LINUX_RELEASE_LINKSFLAGS	:= -fsanitize=address
LINUX_DISTR_LINKSFLAGS		:=

ALWAYS_DEBUG_CFLAGS			:= -g -O0 -fsanitize=address
ALWAYS_DEBUG_LINKFLAGS		:= -fsanitize=address -fsanitize=undefined
ALWAYS_DEBUG_DEFINES		:= -DFDF_DEBUG

ALWAYS_RELEASE_CFLAGS		:= -g -O2 -fsanitize=address
ALWAYS_RELEASE_LINKFLAGS	:= -fsanitize=address -fsanitize=undefined
ALWAYS_RELEASE_DEFINES		:= -DFDF_RELEASE

ALWAYS_DISTR_CFLAGS			:= -Ofast -g0
ALWAYS_DISTR_LINKFLAGS		:=
ALWAYS_DISTR_DEFINES		:= -DFDF_DISTRIBUTION

SILENT		:= @
ifdef verbose
	SILENT	:=
endif

ifndef config
	config := debug_osx
endif

ifeq ($(config), debug_linux)
	ALL_CFLAGS		+= $(ALWAYS_DEBUG_CFLAGS) $(LINUX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(LINUX_ALWAYS_LINKFLAGS) $(LINUX_DEBUG_LINKFLAGS)
	DEFINES			+= $(LINUX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(LINUX_MLX_LIB)
else ifeq ($(config), release_linux)
	ALL_CFLAGS		+= $(ALWAYS_RELEASE_CFLAGS) $(LINUX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(LINUX_ALWAYS_LINKFLAGS) $(LINUX_DEBUG_LINKFLAGS)
	DEFINES			+= $(LINUX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(LINUX_MLX_LIB)
else ifeq ($(config), distr_linux)
	ALL_CFLAGS		+= $(ALWAYS_DISTR_CFLAGS) $(LINUX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(LINUX_ALWAYS_LINKFLAGS) $(LINUX_DISTR_LINKSFLAGS)
	DEFINES			+= $(LINUX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(LINUX_MLX_LIB)
else ifeq ($(config), debug_osx)
	ALL_CFLAGS		+= $(ALWAYS_DEBUG_CFLAGS) $(OSX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(OSX_ALWAYS_LINKFLAGS) $(OSX_DEBUG_LINKFLAGS)
	DEFINES			+= $(OSX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(OSX_MLX_LIB)
else ifeq ($(config), release_osx)
	ALL_CFLAGS		+= $(ALWAYS_RELEASE_CFLAGS) $(OSX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(OSX_ALWAYS_LINKFLAGS) $(OSX_DEBUG_LINKFLAGS)
	DEFINES			+= $(OSX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(OSX_MLX_LIB)
else ifeq ($(config), distr_osx)
	ALL_CFLAGS		+= $(ALWAYS_DISTR_CFLAGS) $(OSX_ALWAYS_CFLAGS)
	ALL_LINKFLAGS	+= $(ALWAYS_DEBUG_LINKFLAGS) $(OSX_ALWAYS_LINKFLAGS) $(OSX_DISTR_LINKSFLAGS)
	DEFINES			+= $(OSX_ALWAYS_DEFINES)
	DEPENDENCIES	+= $(OSX_MLX_LIB)
else
	$(error "Invalid config $(config)")
endif

all: $(TARGET)

$(TARGET): $(OBJ_FILES) $(DEPENDENCIES)
	$(SILENT)echo Linking $@
	$(SILENT)$(LINK_CMD) $(OBJ_FILES) -o $@ $(ALL_LINKFLAGS)

$(INT_DIR)/%.o: %.c
	$(SILENT)echo $(notdir $<)
	$(SILENT)mkdir -p $(INT_DIR)
	$(SILENT)$(CC) $(ALL_CFLAGS) -c $< -o $@

$(LIBFT_LIB):
	$(SILENT)${MAKE} -C $(LIBFT_DIR) -f Makefile config=distr

$(LINUX_MLX_LIB):
	$(SILENT)(cd $(LINUX_MLX_DIR) && ./configure)

$(OSX_MLX_LIB):
	$(SILENT)${MAKE} -C $(OSX_MLX_DIR)

clean:
	$(SILENT)echo Cleaning object files
	$(SILENT)rm -f $(OBJ_FILES)

fclean: clean
	$(SILENT)echo Cleaning $(TARGET)
	$(SILENT)rm -f $(TARGET)

re: fclean all
