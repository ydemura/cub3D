# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ydemura <ydemura@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 21:16:31 by ydemura       #+#    #+#                  #
#    Updated: 2020/11/18 16:15:18 by julia         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strdup.c\
ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c ft_itoa.c ft_strmapi.c\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
get_next_line_utils.c get_next_line.c

OBJ_SRCS = $(SRCS:.c=.o)
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ_BONUS = $(BONUS_SRCS:.c=.o)
LIBC = ar -rcs
FLAGS = -Wall -Wextra -Werror
HEADER_FILE = libft.h get_next_line.h

ifdef BONUS
OBJ_FILES = $(OBJ_SRCS) $(OBJ_BONUS)
else
OBJ_FILES = $(OBJ_SRCS)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(LIBC) $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(FLAGS) -o $@ $<

bonus:
	$(MAKE) BONUS=1 all

clean:
	rm -f $(OBJ_SRCS) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
