NAME			=	so_long

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

MLX_PATH		=	./mlx_linux
MLX			=	$(MLX_PATH)/libmlx.a

SOURCES		=	aux_printers.c main.c mapmaker_fts.c struct_initializers.c map_freer.c\

HEADER			=	./so_long.h

OBJECTS		= 	$(SOURCES:.c=.o)

CC			=	cc
RM			=	rm -f

CFLAGS			=	-Wall -Wextra -Werror -g
MLXFLAGS		=	-L. -lXext -L. -lX11

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJECTS) $(LIBFT) $(MLX) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

$(MLX):
				$(MAKE) -C $(MLX_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MLX_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft mlx_linux
