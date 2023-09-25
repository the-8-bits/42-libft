NAME	= libft.a
CFLAGS	= -Wall -Werror -Wextra -I. -c

PART_1	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_atoi.c
OBJ_1	= $(PART_1:.c=.o)

PART_2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ_2	= $(PART_2:.c=.o)

BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		  ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJ_BONUS = $(BONUS:.c=.o)

PERSONAL = ft_strcat.c ft_strncpy.c
OBJ_PERSONAL = $(PERSONAL:.c=.o)

FILES	= $(PART_1) $(PART_2) $(BONUS) $(PERSONAL)
OBJ		= $(OBJ_1) $(OBJ_2) $(OBJ_BONUS) $(OBJ_PERSONAL)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# A generic rule to build object files (%.o: %.c) with automatic dependency generation
%.o: %.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# .PHONY targets for clean, fclean, all, and re for better Makefile behavior
.PHONY: clean fclean all re
