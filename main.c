#include "so_long.h"

int	ft_error_msg(t_game *game, int code)
{
	if (code == 1)
	ft_printf("ERROR: Invalid map reference\n");
	if (code == 2)
	ft_printf("ERROR: Map is not rectangular\n");
	if (code == 3)
		ft_printf("ERROR: Invalid cell type found\n");
	if (code == 4)
		ft_printf("ERROR: Map lacks full outer wall\n");
	if (code == 5)
	{
		if (game->pec.p != 1)
		ft_printf("ERROR: Duplicate or null player start\n");
		if (game->pec.e != 1)
		ft_printf("ERROR: Duplicate or null exit\n");
		if (game->pec.c == 0)
		ft_printf("ERROR: No collectables found\n");
	}
	if (code > 2)
		map_freer(game);
	return (-1);
}

int	blocks_test(t_game *game, t_xy xy)
{
	if (!(game->map[xy.y][xy.x] == '0' || game->map[xy.y][xy.x] == '1'
		|| game->map[xy.y][xy.x] == 'P' || game->map[xy.y][xy.x] == 'E'
			|| game->map[xy.y][xy.x] == 'C'))
		return(-1);
	return(0);
}

int	walls_test(t_game *game, t_xy xy)
{
	if (xy.y == 0 || xy.y == game->size.y - 1 || xy.x == 0 || xy.x == game->size.x - 1)
	{
		if (game->map[xy.y][xy.x] != '1')
			return(-1);
	}
	return(0);
}

int	amount_test(t_game *game, t_xy xy)
{
	if (game->map[xy.y][xy.x] == 'P')
		game->pec.p++;
	if (game->map[xy.y][xy.x] == 'E')
	  	game->pec.e++;
	if (game->map[xy.y][xy.x] == 'C')
		game->pec.c++;
	game->pec.total = game->pec.p + game->pec.e + game->pec.c;
	if (xy.x == game->size.x - 1 && xy.y == game->size.y - 1 && !(game->pec.c > 0 && game->pec.p == 1 && game->pec.e == 1))
		return (-1);
	return (0);
}

int	basic_error_tester(t_game *game)
{
	t_xy	xy;

	xy = xy_initializer();
	while(xy.y < game->size.y)
	{
		xy.x = 0;
		while (xy.x < game->size.x)
		{
			if (blocks_test(game, xy) == -1)
				return (ft_error_msg(game, 3));
			if (walls_test(game, xy) == -1)
				return (ft_error_msg(game, 4));
			if (amount_test(game, xy) == -1)
				return (ft_error_msg(game, 5));
			xy.x++;
		}
		xy.y++;
	}
	return(1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game = game_initializer();
	if (argc != 2 || file_check(argv[1]) == -1)
		return(ft_error_msg(&game, 1));
	game.size = get_map_size(argv[1]);
	/*if (game.size.x == -1)
		return(ft_error_msg(&game, 2));
	game.map = malloc((game.size.y + 1) * sizeof(char *));
	get_map(argv[1], &game);
	map_printer(game);
	if (basic_error_tester(&game) == -1)
		return(-1);*/
	return (0);
}
