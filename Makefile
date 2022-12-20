GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

# GLFW_LIB = -L /opt/homebrew/Cellar/glfw/3.3.6/lib # pro
GLFW_LIB = -L /opt/homebrew/Cellar/glfw/3.3.8/lib # iMac

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			main.c\
			draw3D.c\
			src/check_map_borders.c\
			src/colours.c\
			src/error_handling.c\
			src/exam_gnl.c\
			src/form_data_structure.c\
			src/form_grid.c\
			src/initiate_data.c\
			src/initiate_map_size.c\
			src/map_utils.c\
			src/parsing_gamestate.c\
			src/textures.c\
			distance_ray.c\
			keyboard.c \
			key_moves.c

OBJS	= $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_LIB = libft.a

NAME	= cub3d

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror -g


HEADER_FILE =	cub3d.h\
				includes

MLX_DIR	= minilibx_opengl

MLX_LIB = libmlx42.a

LINKS =  -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	# //mac use 
	# $(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB) $(GLFW_LIB)  $(LINKS)
	# codam use
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB) $(LINKS)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

run: all 
	./$(NAME) maps_variations/ali_maps.cub
clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Succesfully removed all object files!$(NORMAL)"

fclean: clean
	@echo "$(RED)Removing libraries and bitmap file...$(NORMAL)"
	rm -f $(NAME)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)Successfully removed libraries and bitmap file!$(NORMAL)"

re: fclean all

.PHONY:	clean fclean re