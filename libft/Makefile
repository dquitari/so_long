NAME = libft.a

SRCS = ft_memcpy.c get_next_line.c ft_strchr.c ft_strjoin.c ft_abs.c ft_atoi.c ft_itoa.c ft_lstadd_back.c ft_lstlast.c ft_lstsize.c ft_print_char.c ft_printf.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c ft_print_str.c ft_print_unbr.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c \

CC       = gcc
CFLAGS   = -Wall -Wextra -Werror -g
LIBFLAGS = ar -rcs
RM       = rm -f
SRCS_O  := $(SRCS:.c=.o)
OBJS    := $(SRCS_O)

all: $(NAME)

$(NAME): $(OBJS)
	$(LIBFLAGS) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
