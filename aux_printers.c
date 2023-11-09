#include "so_long.h"

void	map_printer(t_game game)
{
	int	y;

	y = 0;
	while (y < game.size.y)
	{
		ft_printf("%s", game.map[y]);
		y++;
	}
}

/*void	coords_printer(t_game game)
{
	t_xy	xy;

	xy = xy_initializer();
	while (xy.y < game.pec.total)
	{
		while (game.coords[xy.y][xy.x])
		{
			if (game.coords[xy.y][xy.x] >= '0')
				ft_printf("%c ", game.coords[xy.y][xy.x]);
			else
				ft_printf("%d ", game.coords[xy.y][xy.x]);
			xy.x++;
		}
		ft_printf("\n");
		xy.x = 0;
		xy.y++;
	}	
}

void	list_printer(t_walk_list *wl)
{
	t_walk_list	*aux;

	aux = wl;
	while (aux)
	{
		ft_printf("x (%d) | y (%d) | i (%d) | landmark (%c)\n", aux->x, aux->y, aux->index, aux->landmark);
		aux = aux->next;
	}
	ft_printf("\n");
}*/
