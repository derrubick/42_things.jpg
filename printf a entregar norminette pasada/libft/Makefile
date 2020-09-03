# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vnastase <valentin.parla@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/03 19:51:18 by vnastase          #+#    #+#              #
#    Updated: 2020/09/03 19:51:44 by vnastase         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_calloc.c ft_strlcpy.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c\
			ft_putstr_fd.c ft_strchr.c \
			ft_strdup.c ft_strjoin.c \
			ft_strlcat.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_split.c \
			ft_strtrim.c ft_tolower.c ft_toupper.c

SRCS_BONUS = ft_atoi.c ft_bzero.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_calloc.c ft_strlcpy.c\
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c\
			ft_putstr_fd.c ft_strchr.c \
			ft_strdup.c ft_strjoin.c \
			ft_strlcat.c ft_strlen.c ft_strmapi.c \
			ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_split.c \
			ft_strtrim.c ft_tolower.c ft_toupper.c \
			ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c ft_lstclear_bonus.c \
			ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES = ./

all: $(NAME)

$(NAME): $(SRCS) libft.h
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

$(NAME): $(SRCS_BONUS) libft.h
	gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS_BONUS)
	ar rc $(NAME) $(OBJECTS_BONUS)
	ranlib $(NAME)
