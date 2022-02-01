.SUFFIXES:
TARGET						:= fdf
TEST_TARGET					:= fdf_tests

DEPEND_DIR 					:= ./Dependencies
VENDOR_DIR 					:= ./Vendor
INT_DIR 					:= ./obj
LIBFT_DIR					:= $(DEPEND_DIR)/libft
LIBFT_LIB					:= $(LIBFT_DIR)/libft.a

OSX_MLX_DIR					:= $(VENDOR_DIR)/minilibx-macos
OSX_MLX_LIB					:= $(OSX_MLX_DIR)/libmlx.a
LINUX_MLX_DIR				:= $(VENDOR_DIR)/minilibx-linux
LINUX_MLX_LIB				:= $(LINUX_MLX_DIR)/libmlx_Linux.a
DEPENDENCIES				:= $(LIBFT_LIB)

SRC_DIR						:= ./src

TEST_DIR					:= ./tests
TEST_SRCS					:= simple_tests.cpp test.cpp
TEST_OBJS					:= $(addprefix $(INT_DIR)/,$(TEST_SRCS:%.cpp=%.o))

SRC_FILES					:= fdf.c matrix4f_mulm.c matrix4f_mulv.c matrix4f_ortho.c \
								matrix4f_transpose.c matrix4f_clear.c matrix4f_rotation.c \
								matrix4f_mulva.c matrix4f_identity.c \
								matrix4f_translation.c matrix4f_scale.c \
								window_destroy.c window_init.c window_update.c \
								safe_malloc.c file_utils.c \
								assert.c vector4f_add.c \
								vector4f_dot.c vector4f_muls.c vector4f_convert.c \
								vector2i_zero.c vector2i_convert.c vector2i_constructor.c \
								vector3f_constructor.c vector3f_inverse.c vector3f_normalize.c \
								vector3f_magnitude.c \
								vector2f_convert.c \
								image_buffer_clear.c image_buffer_create.c \
								image_buffer_destroy.c image_buffer_flush.c \
								image_buffer_put_pixel.c image_buffer_put.c \
								color_encode.c color_colors.c \
								renderer_render_line.c renderer_render_quads.c \
								renderer_render_quads_ndc.c \
								parser_parse_map.c \
								map_create.c map_init.c
OBJ_FILES					:= $(addprefix $(INT_DIR)/,$(SRC_FILES:%.c=%.o))

VPATH						:= $(SRC_DIR) $(SRC_DIR)/math $(SRC_DIR)/math/matrix4f \
								$(SRC_DIR)/gfx/window $(SRC_DIR)/util \
								$(SRC_DIR)/math/vector4f $(SRC_DIR)/gfx/image_buffer \
								$(SRC_DIR)/gfx/color $(SRC_DIR)/gfx/renderer \
								$(SRC_DIR)/math/vector2i $(SRC_DIR)/map \
								$(SRC_DIR)/math/vector3f $(SRC_DIR)/math/vector2f \
								$(SRC_DIR)/parser/map_parser $(TEST_DIR)

DEFINES						:=
INCLUDE_DIRS				:= -I $(LIBFT_DIR)/include -I $(SRC_DIR)
LIBRARIES					:= $(LIBFT_LIB) $(MLX_LIB) This is an error check

CC							:= clang
CXX							:= clang++
LINK_CMD					:= clang++

ALL_CFLAGS					:= -std=c89 -Wall -Wextra -Werror -pedantic $(INCLUDE_DIRS)
ALL_CXXFLAGS				:= -std=c++17 -Wall -Wextra -pedantic $(INCLUDE_DIRS)
ALL_LINKFLAGS				:= -L$(LIBFT_DIR) -lft

OSX_ALWAYS_LINKFLAGS		:= -L$(OSX_MLX_DIR) -lmlx -framework OpenGL -framework AppKit
OSX_ALWAYS_CFLAGS			:= -I$(OSX_MLX_DIR)
OSX_ALWAYS_DEFINES			:= $(OSX_DEBUG_DEFINES)
OSX_DEBUG_LINKFLAGS			:= -fsanitize=address
OSX_RELEASE_LINKSFLAGS		:= -fsanitize=address
OSX_DISTR_LINKSFLAGS		:=

LINUX_ALWAYS_LINKFLAGS		:= -L$(LINUX_MLX_DIR) -lmlx -lX11 -lXext -lm -lz
LINUX_ALWAYS_CFLAGS			:= -I $(LINUX_MLX_DIR)
LINUX_ALWAYS_DEFINES		:= -DFDF_PLATFORM_LINUX
LINUX_DEBUG_LINKFLAGS		:= -fsanitize=address
LINUX_RELEASE_LINKSFLAGS	:= -fsanitize=address
LINUX_DISTR_LINKSFLAGS		:=

ALWAYS_DEBUG_CFLAGS			:= -g3 -O0 -fsanitize=address
ALWAYS_DEBUG_CXXFLAGS			:= -g3 -O0 -fsanitize=address
ALWAYS_DEBUG_LINKFLAGS		:= -fsanitize=address -fsanitize=undefined
ALWAYS_DEBUG_DEFINES		:= -DFDF_DEBUG

ALWAYS_RELEASE_CFLAGS		:= -g3 -O2 -fsanitize=address
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
	ALL_CXXFLAGS		+= $(ALWAYS_DEBUG_CXXFLAGS)
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

test: SRC_FILES := $(filter-out fdf.c,$(SRC_FILES))
test: OBJ_FILES := $(filter-out $(INT_DIR)/fdf.o,$(OBJ_FILES))
test: $(TEST_TARGET)

$(TARGET): $(OBJ_FILES) $(DEPENDENCIES)
	$(SILENT)echo Linking $@
	$(SILENT)$(LINK_CMD) $(OBJ_FILES) -o $@ $(ALL_LINKFLAGS)

$(TEST_TARGET): $(OBJ_FILES) $(DEPENDENCIES) $(TEST_OBJS)
	$(SILENT)echo Linking $@
	$(SILENT)$(LINK_CMD) $(OBJ_FILES) $(TEST_OBJS) -o $@ $(ALL_LINKFLAGS)


$(INT_DIR)/%.o: %.cpp
	$(SILENT)echo $(notdir $<)
	$(SILENT)mkdir -p $(INT_DIR)
	$(SILENT)$(CXX) $(ALL_CXXFLAGS) -c $< -o $@

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
	$(SILENT)rm -f $(TEST_OBJS)

fclean: clean
	$(SILENT)echo Cleaning $(TARGET)
	$(SILENT)rm -f $(TARGET)
	$(SILENT)echo Cleaning $(TEST_TARGET)
	$(SILENT)rm -f $(TEST_TARGET)

re: fclean all
