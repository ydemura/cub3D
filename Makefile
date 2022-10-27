NAME = cube3D
SRCS = src/*.c
		

OBJ = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra  -g
LIBMLX_FILE = libmlx.dylib
LIBFT = libft_norme3
HEADER = includes
CC = gcc

all: $(NAME)

$(NAME): $(OBJ) $(LIBMLX_FILE) $(LIBFT)
	$(CC) $(OBJ) $(LIBMLX_FILE) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBMLX_FILE):
	cp mlx/libmlx.dylib .

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c -o $@ $< -I ./cubik_xcode_part/cubik_xcode_part -I ./cubik_xcode_part/cubik_xcode_part/libft_for_cube -I ./cubik_xcode_part/cubik_xcode_part/algoritm -I ./mlx/mlx.h

$(LIBFT):
	$(MAKE) -C cubik_xcode_part/cubik_xcode_part/libft_for_cube

clean:
	rm -f $(OBJ) $(LIBMLX_FILE)
	rm -f cubik_xcode_part/cubik_xcode_part/object_files_can/*.o

fclean: clean
	rm -f $(NAME)
	rm -f cubik_xcode_part/cubik_xcode_part/object_files_can/*.o

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

#https://makefiletutorial.com/


# https://noahloomans.com/tutorials/makefile-2.0/ - feedback 

















# working before adding algoritm:

# NAME = cubic_result
# SRCS =	cubik_xcode_part/cubik_xcode_part/main.c \
# 		cubik_xcode_part/cubik_xcode_part/exam_gnl.c \
# 		cubik_xcode_part/cubik_xcode_part/error_handling.c \
# 		cubik_xcode_part/cubik_xcode_part/form_gamestate.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_header/initiate_struct.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_header/colours_check_and_collect.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_header/resolution_collect.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_header/collect_path_from_str.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_header/parse_info_from_header_map.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_map/utilities_tiles.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_map/count_map_size.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_map/read_map.c \
# 		cubik_xcode_part/cubik_xcode_part/work_with_map/read_map_addition.c \
		

# OBJ = $(SRCS:.c=.o)

# FLAGS = -Wall -Wextra  -g
# LIBMLX_FILE = libmlx.dylib
# LIBFT = cubik_xcode_part/cubik_xcode_part/libft_for_cube/libft.a

# HEADER =	cubik_xcode_part/cubik_xcode_part/header_all.h \
# 			cubik_xcode_part/cubik_xcode_part/parsing_header.h
# CC = gcc

# all: $(NAME)

# $(NAME): $(OBJ) $(LIBMLX_FILE) $(LIBFT)
# 	$(CC) $(OBJ) $(LIBMLX_FILE) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# $(LIBMLX_FILE):
# 	cp mlx/libmlx.dylib .

# %.o: %.c $(HEADER)
# 	gcc $(FLAGS) -c -o $@ $< -I ./cubik_xcode_part/cubik_xcode_part -I ./cubik_xcode_part/cubik_xcode_part/libft_for_cube

# $(LIBFT):
# 	$(MAKE) -C cubik_xcode_part/cubik_xcode_part/libft_for_cube

# clean:
# 	rm -f $(OBJ) $(LIBMLX_FILE)
# 	rm -f cubik_xcode_part/cubik_xcode_part/object_files_can/*.o

# fclean: clean
# 	rm -f $(NAME)
# 	rm -f cubik_xcode_part/cubik_xcode_part/object_files_can/*.o

# re:
# 	$(MAKE) fclean
# 	$(MAKE) all

# .PHONY: all clean fclean re
