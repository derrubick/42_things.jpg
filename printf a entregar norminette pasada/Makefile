
NAME = libftprintf.a

HEADER = ./libft/libft.h

NAME =			$(FT_LIB)

FT_LIB_NAME =	ftprintf

FT_LIB =		lib$(FT_LIB_NAME).a

CC =			gcc

FLAGS =			-Wall -Werror -Wextra

HEADER =		$(FT_SRC_DIR)libft.h

FT_SRC_DIR =	./libft/

PRINTF_HEADER =	$(PRINTF_DIR)ft_printf.h

PRINTF_DIR =	./printf/

FT_CMP =	ft_atoi.c ft_bzero.c ft_isalnum.c \
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
			ft_lstmap_bonus.c ft_lstiter_bonus.c ft_lstnew_bonus.c \
			ft_putnbr_base_fd.c

FT_COMPILED = $(FT_CMP:.c=.o)

PRINTF_CMPLD =	ft_printf.o ft_d_conversion.o ft_c_conversion.o ft_s_conversion.o \
				ft_p_conversion.o ft_conversion_utils.o ft_conversion_utils_2.o \
				ft_x_conversion.o ft_x2_conversion.o ft_pct_conversion.o \
				ft_u_conversion.o
COMPILED =		$(FT_COMPILED) $(PRINTF_CMPLD)

all: $(FT_LIB)

$(FT_LIB): $(COMPILED)
	ar rc $(FT_LIB) $(COMPILED)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)%.c $(HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_CMPLD): %.o: $(PRINTF_DIR)%.c $(PRINTF_HEADER)
	$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_DIR) $< -o $@

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(FT_LIB)

re: fclean all
