#include "so_long.h"

t_xy	xy_initializer()
{
	t_xy	new;

	new.x = 0;
	new.y = 0;
	return (new);
}

t_pec	pec_initializer()
{
	t_pec	new;

	new.p = 0;
	new.e = 0;
	new.c = 0;
	new.total = 0;
	return (new);
}

t_img	img_initializer()
{
	t_img	img;
	
	img.p = NULL;
	img.one = NULL;
	img.zero = NULL;
	img.e_0 = NULL;
	img.e_1 = NULL;
	img.c_0 = NULL;
	img.c_1 = NULL;
	return (img);
}

t_game	game_initializer()
{
	t_game	new;
	
	new.img = img_initializer();
	new.mlx = NULL;
	new.win = NULL;
	new.map = NULL;
	new.coords = NULL;
	new.size.x = 0;
	new.size.y = 0;
	new.pec.p = 0;
	new.pec.e = 0;
	new.pec.c = 0;
	new.pec.total = 0;
	new.moves = 0;
	return (new);
}
