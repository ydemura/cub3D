GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			main.c\
			keyboard.c\
			check_position.c

OBJS	= $(SRCS:.c=.o)

LIBFT_DIR = libft

LIBFT_LIB = libft.a

NAME	= cub3d

GCC		= gcc

FLAGS	= -Wall -Wextra -Werror

HEADER_FILE = cub3d.h

MLX_DIR	= minilibx_opengl

MLX_LIB = libmlx.a

LINKS = -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME):	$(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(GCC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_LIB) $(MLX_DIR)/$(MLX_LIB) $(LINKS)

%.o: %.c $(HEADER_FILE)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)
	@echo "$(GREEN)Successfully compiled!$(NORMAL)"

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