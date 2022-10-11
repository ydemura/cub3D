NAME = result_cubik
SRCS =	src_includes/main.c \
		src_includes/exam_gnl.c \
		src_includes/error_handling.c \
		src_includes/form_gamestate.c \
		src_includes/work_with_header/initiate_struct.c \
		src_includes/work_with_header/colours_check_and_collect.c \
		src_includes/work_with_header/resolution_collect.c \
		src_includes/work_with_header/collect_path_from_str.c \
		src_includes/work_with_header/parse_info_from_header_map.c \
		src_includes/work_with_map/utilities_tiles.c \
		src_includes/work_with_map/count_map_size.c \
		src_includes/work_with_map/read_map.c \
		src_includes/work_with_map/read_map_addition.c \
		src_includes/algoritm/open_window_start_drawing.c \
		

OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra  -g
LIBMLX_FILE = libmlx.dylib
LIBFT = src_includes/libft_for_cube/libft.a
HEADER = src_includes/header_all.h
CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(LIBMLX_FILE) $(LIBFT)
	$(CC) $(OBJ) $(LIBMLX_FILE) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBMLX_FILE):
	cp mlx/libmlx.dylib .

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c -o $@ $< -I ./src_includes -I ./src_includes/libft_for_cube -I ./src_includes/algoritm -I ./mlx/mlx.h

$(LIBFT):
	$(MAKE) -C /src_includes/libft_for_cube

clean:
	rm -f $(OBJ) $(LIBMLX_FILE)
	rm -f /src_includes/object_files_can/*.o

fclean: clean
	rm -f $(NAME)
	rm -f /src_includes/object_files_can/*.o

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

#https://makefiletutorial.com/
# https://noahloomans.com/tutorials/makefile-2.0/

















# working before adding algoritm:

# NAME = cubic_result
# SRCS =	src_includes/src_includes/main.c \
# 		src_includes/src_includes/exam_gnl.c \
# 		src_includes/src_includes/error_handling.c \
# 		src_includes/src_includes/form_gamestate.c \
# 		src_includes/src_includes/work_with_header/initiate_struct.c \
# 		src_includes/src_includes/work_with_header/colours_check_and_collect.c \
# 		src_includes/src_includes/work_with_header/resolution_collect.c \
# 		src_includes/src_includes/work_with_header/collect_path_from_str.c \
# 		src_includes/src_includes/work_with_header/parse_info_from_header_map.c \
# 		src_includes/src_includes/work_with_map/utilities_tiles.c \
# 		src_includes/src_includes/work_with_map/count_map_size.c \
# 		src_includes/src_includes/work_with_map/read_map.c \
# 		src_includes/src_includes/work_with_map/read_map_addition.c \
		

# OBJ = $(SRCS:.c=.o)

# FLAGS = -Wall -Wextra  -g
# LIBMLX_FILE = libmlx.dylib
# LIBFT = src_includes/src_includes/libft_for_cube/libft.a

# HEADER =	src_includes/src_includes/header_all.h \
# 			src_includes/src_includes/parsing_header.h
# CC = gcc

# all: $(NAME)

# $(NAME): $(OBJ) $(LIBMLX_FILE) $(LIBFT)
# 	$(CC) $(OBJ) $(LIBMLX_FILE) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(LIBMLX_FILE):
# 	cp mlx/libmlx.dylib .

# %.o: %.c $(HEADER)
# 	gcc $(FLAGS) -c -o $@ $< -I ./src_includes/src_includes -I ./src_includes/src_includes/libft_for_cube

# $(LIBFT):
# 	$(MAKE) -C src_includes/src_includes/libft_for_cube

# clean:
# 	rm -f $(OBJ) $(LIBMLX_FILE)
# 	rm -f src_includes/src_includes/object_files_can/*.o

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f src_includes/src_includes/object_files_can/*.o

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# .PHONY: all clean fclean re