#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


typedef struct s_xy
{
	int	x;
	int	y;
}	t_xy;

typedef struct s_pec
{
	int	p;
	int	e;
	int	c;
	int	total;
}	t_pec;

typedef struct s_img
{
	void	*p;
	void	*one;
	void	*zero;
	void	*e_0;
	void	*e_1;
	void	*c_0;
	void	*c_1;
}	t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
	char	**map;
	char	**coords;
	t_xy	size;
	t_pec	pec;
	int	moves;
}	t_game;



void	game_start(t_game game);
int	game_end(t_game game);

//RENDER

void	render(t_game game);

//KEYPRESS FTS.

int	ft_keypress(int keycode, t_game *game);

//AUX PRINTERS

void	map_printer(t_game game);
void	coords_printer(t_game game);
void	list_printer(t_walk_list *wl);

//FREER FTS.

void    map_freer(t_game *game);
void	list_freer(t_walk_list *wl);
int	ft_alloc_freer(t_game game);
//MAPMAKING FTS

//checks file validity and .ber file type:
int	file_check(char *filename);
//tests map validity(lines of same size) and gets t_xy size:
t_xy	get_map_size(char *filename);
//assigns read lines to char **map (caution, lines end in NEWLINE):
void	get_map(char *filename, t_game *game);

//OPENING TEST FTS


//STRUCT INITIALIZERS

t_pec		pec_initializer();
t_xy		xy_initializer();
t_img		img_initializer();
t_game		game_initializer();
//t_uldr		uldr_initializer();

#endif
