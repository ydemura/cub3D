# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: adoner <adoner@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/16 15:28:02 by adoner        #+#    #+#                  #
#    Updated: 2020/11/23 11:52:33 by adoner        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #



NAME 	=	libft.a

SOURCE 	=	ft_atoi.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
					ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
					ft_putchar_fd.c ft_strncmp.c ft_strlcpy.c ft_memset.c\
					ft_bzero.c ft_memcpy.c ft_strnstr.c ft_strchr.c\
					ft_strrchr.c  ft_strlcat.c ft_putendl_fd.c ft_putnbr_fd.c\
					ft_strmapi.c ft_strtrim.c ft_memcmp.c ft_memmove.c \
		  			ft_calloc.c	 ft_strdup.c  ft_putstr_fd.c ft_substr.c\
					ft_strjoin.c ft_memccpy.c ft_memchr.c ft_itoa.c ft_split.c \

BONUS =		ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c\
					ft_lstnew.c ft_lstsize.c ft_lstadd_front.c ft_lstlast.c

CFLAGS = -Wall -Wextra -Werror

HEADER_FILES = libft.h

REG_OBJ_FILES = $(SOURCE:.c=.o)

BONUS_OBJ_FILES = $(BONUS:.c=.o)

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

GREEN = \033[38;5;2m
NORMAL = \033[38;5;255m
RED = \033[38;5;1m
BLUE = \033[38;5;4m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rc $@ $^

%.o: %.c $(HEADER_FILES)
	@echo "$(GREEN)Compiling:$(NORMAL)"
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	@echo "$(RED)Removing all object files...$(NORMAL)"
	rm -f $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
	@echo "$(GREEN)Succesfully removed all object files!"

fclean: clean
	@echo "$(RED)Removing libft.a...$(NORMAL)"
	rm -f $(NAME)
	@echo "$(GREEN)Successfully removed libft.a!"

re: fclean all

.PHONY: all clean fclean re
