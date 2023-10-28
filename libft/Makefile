# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrodri <gabrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 14:29:39 by gabrodri          #+#    #+#              #
#    Updated: 2023/10/10 18:34:01 by gabrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME is the name of the library to be created
NAME	= libft.a

# CFLAGS are flags passed to the compiler. -Wall -Werror -Wextra are used to
CFLAGS	= -Wall -Werror -Wextra -I. -c

# PART_1 is the first part of the mandatory functions to be coded
PART_1	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c

# OBJ_1 is the object files for the first part of the mandatory functions
OBJ_1	= $(PART_1:.c=.o)

# PART_2 is the second part of the mandatory functions to be coded
PART_2	= ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c

# OBJ_2 is the object files for the second part of the mandatory functions
OBJ_2	= $(PART_2:.c=.o)

# BONUS is the bonus part of the functions to be coded
BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c

# OBJ_BONUS is the object files for the bonus part of the functions
OBJ_BONUS	= $(BONUS:.c=.o)

# FILES is the list of all the files to be compiled
FILES	= $(PART_1) $(PART_2) $(BONUS)

# OBJ is the list of all the object files to be created
MANDT_OBJ	= $(OBJ_1) $(OBJ_2)
BONUS_OBJ	= $(OBJ_1) $(OBJ_2) $(OBJ_BONUS)

# The rule to compile all the files
all: $(NAME)

# The rule to compile the library without the bonus
$(NAME): $(MANDT_OBJ)
# ar: create, replace, and index; -options
	@echo "------------------------------------"
	@echo "Compiling the Library (no bonus)"
	@echo "------------------------------------"
	ar -rc $(NAME) $(MANDT_OBJ) 

# The rule to compile the library with mandatory and bonus
bonus: $(BONUS_OBJ)
	@echo "------------------------------------"
	@echo "Compiling the Library (w/ bonus)"
	@echo "------------------------------------"
	ar -rc $(NAME) $(BONUS_OBJ) 

# The rule to clean the object files
clean:
	@echo "------------------------------------"
	@echo "Cleaning the object files"
	@echo "------------------------------------"
	rm -f $(MANDT_OBJ) $(BONUS_OBJ)

# The rule to clean the object files and the library
fclean: clean
	@echo "------------------------------------"
	@echo "Cleaning the object files and the library"
	@echo "------------------------------------"
	rm -f $(NAME)

# The rule to clean the object files, the library, and recompile
re: fclean all

# The rule to clean the object files, the library, and recompile with bonus
# .PHONY targets for clean, fclean, all, and re for better Makefile behavior
.PHONY: clean fclean all re
