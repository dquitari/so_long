/*drawers to imagers -- most pertinent
example.c -- barebones tester, prints image and moves it
MLX CodamMLX

     x   y
char[7][7]

1111111
1E C  1
11111 1
1  P C1
1 11111
1  C C1
1111111
*/


#include "so_long.h"


//INITIALIZER


t_xy	xy_initializer()
{
	t_xy	new;

	new.x = 0;
	new.y = 0;
	return (new);
}

t_landmarks	lm_initializer()
{
	t_landmarks	new;

	new.p = 0;
	new.e = 0;
	new.c = 0;
	new.v = 0;
	new.total = 0;
	return (new);
}


//PRINTER FUNCTIONS


void	lm_coords_printer(char **lm_coords, t_landmarks lm)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < lm.total)
	{
		while (x < 3)
		{
			if (x == 2)
				ft_printf("%c ", lm_coords[y][x++]);
			else
				ft_printf("%d ", lm_coords[y][x++]);
		}
		ft_printf("\n");
		x = 0;
		y++;
	}
}




/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;*/


/*what_is_actually_supposed_to_happen(map,  simple_map_maker(map), size, lm_coords);
}*/


/*void	what_is_actually_supposed_to_happen(char **map, char **simple_map, t_xy size, char **lm_coords)
{
	t_xy	player;

	player.x = lm_coords[0][0] - '0';
	player.y = lm_coords[0][1] - '0';
	if ((w || up) && simple_map[player_coords.x][player_coords.y - 1] == '0')
		player.y--;
	if ((a || left) && simple_map[player_coords.x - 1][player_coords.y] == '0')
		player.x--;
	if ((s || down) && simple_map[player_coords.x][player_coords.y + 1] == '0')
		player.y++;
	if ((d || right) && simple_map[player_coords.x + 1][player_coords.y] == '0')
		player.x++;
}*/


char	**simple_map_maker(char **map)
{
	char	**simple_map;
	t_xy	xy;

	simple_map = map;
	xy = xy_initializer();
	while (simple_map[0][xy.y])
	{
		while (simple_map[xy.x][xy.y])
		{
			if (simple_map[xy.x][xy.y] == 'P' || simple_map[xy.x][xy.y] == 'E' || simple_map[xy.x][xy.y] == 'C' || simple_map[xy.x][xy.y] == 'V')
				simple_map[xy.x][xy.y] = '0';
			xy.x++;
		}
		xy.x = 0;
		xy.y++;
	}
	return (simple_map);
}


/*int	first_sweep(char **map, t_landmarks lm, char **lm_coords)
{
	t_xy	p;
	int	tally;

	p.x = lm_coords[0][0] - '0';
	p.y = lm_coords[0][1] - '0';
	tally = 1;
	p = rotate_cycle(p, map, lm_coords);
		if (p.x == -1)
			return (-1);
	while (lm_coords[0][0] - '0' != p.x || lm_coords[0][0] - '0' != p.y)
	{
		if ((map[p.x][p.y] == 'P' || map[p.x][p.y] == 'E' || map[p.x][p.y] == 'C') && coords_tally_update(lm_coords, p) == 1)
			tally++;
		p = rotate_cycle(p, map, lm_coords);
	}
	if (coord_tally_total(lm_coords) == 1)
		return (1);
	return (0);
}*/

int	coords_tally_total(char **lm_coords)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lm_coords[i][2])
	{
		if (lm_coords[i][2] == 1)
			j++;
		i++;
	}
	if (i == j)
		return (1);
	else
		return (-1);
}


int	coords_tally_update(char **lm_coords, t_xy b)
{
	int	i;

	i = 0;
	while (lm_coords[i])
	{
		if (lm_coords[i][0] == b.x && lm_coords[i][1] == b.y)
		{
			lm_coords[i][2] = '1';
			return (1);
		}
		i++;
	}
	return (-1);
}


// -1 represents an error condition (for instance, here it means the player can't go left, up, right or down), 1 represents goal condition (all landmarks crossed), 0 represents insufficient info (not all landmarks crossed)


/*t_xy	rotate_cycle(t_xy p, char **map, char **lm_coords)
{
	int	phase;

	phase = rotate_phase(p, map);
	if (phase == -1)
		p.x = -1;
		return (p);
	if (phase == 0)
		p.x--;
	if (phase == 1)
		p.y--;
	if (phase == 2)
		p.x++;
	if (phase == 3)
		p.y++;
	return (p);
}*/


/*int	rotate_phase(t_xy p, char **map)
{
	if (map[p.x - 1][p.y] != '1')
		return (0);
	else if (map[p.x][p.y - 1] != '1')
		return (1);
	else if (map[p.x + 1][p.y] != '1')
		return (2);
	else if (map[p.x][p.y + 1] != '1')
		return (3);
	return (-1);
}*/














//PATH TEST

int	ft_add_node(t_walk_list **wl, int x, int y, int index)
{
	t_walk_list	*aux;
	t_walk_list	*new_node;

	aux = *wl;
	while (aux)
	{
		if (aux->x == x && aux->y == y)
			return (0);
		else
			aux = aux->next;
	}
	new_node = (t_walk_list *)malloc(sizeof(t_walk_list));
	new_node->x = x;
	new_node->y = y;
	new_node->index = index;
	ft_lstadd_back(wl, new_node);
	return (1);
}

void	list_printer(t_walk_list *wl)
{
	t_walk_list	*aux;

	aux = wl;
	while (aux)
	{
		ft_printf("x(%d) - y(%d) - i(%d)\n", aux->x, aux->y, aux->index);
		aux = aux->next;
	}
	ft_printf("\n\n");
}

void	list_maker(t_walk_list *wl, char **map, t_xy size)
{
	t_walk_list *aux;
	static int	index;
	int	start_index;

	aux = wl;
	start_index = index;
	index = 1;
	while (aux)
	{
		if (aux->y - 1 > 0 && map[aux->y - 1][aux->x] != '1')
			index += ft_add_node(&wl, aux->x, aux->y - 1, index);
		if (aux->x - 1 > 0 && map[aux->y][aux->x - 1] != '1')
			index += ft_add_node(&wl, aux->x - 1, aux->y, index);
		if (aux->y + 1 < size.y - 1 && map[aux->y + 1][aux->x] != '1')
			index += ft_add_node(&wl, aux->x, aux->y + 1, index);
		if (aux->x + 1 < size.x - 1 && map[aux->y][aux->x + 1] != '1')
			index += ft_add_node(&wl, aux->x + 1, aux->y, index);
		aux = aux->next;
	}
	//list_printer(wl);
	if (start_index != index)
		list_maker(wl, map, size);
}


char	**lm_coord_line_filler(char **lm_coords, char type, t_xy xy)
{
	static int	i = 2;
	
	if (type == 'P')
	{
		lm_coords[0][0] = xy.x;
		lm_coords[0][1] = xy.y;
		lm_coords[0][2] = type;
	}
	if (type == 'E')
	{
		lm_coords[1][0] = xy.x;
		lm_coords[1][1] = xy.y;
		lm_coords[1][2] = type;
	}
	if (type == 'C')
	{
		lm_coords[i][0] = xy.x;
		lm_coords[i][1] = xy.y;
		lm_coords[i][2] = type;
		i++;
	}
	/*if (type == 'V')
	{
		lm_coords[i + lm.c][0] = xy.x;
		lm_coords[i + lm.c][1] = xy.y;
		lm_coords[i + lm.c][2] = type;
		i++;
	}*/
	return (lm_coords);
}
//lm_coords and i values must update. use pointers


char	**lm_coords_filler(char **map, t_xy size, char **lm_coords)
{
	t_xy	xy;

	xy = xy_initializer();
	while (xy.y < size.y)
	{
		while (xy.x < size.x)
		{
			if (map[xy.y][xy.x] == 'P' || map[xy.y][xy.x] == 'E' || map[xy.y][xy.x] == 'C')
				lm_coords = lm_coord_line_filler(lm_coords, map[xy.y][xy.x], xy);
			xy.x++;
		}
		xy.x = 0;
		xy.y++;
	}
	return (lm_coords);
}

char	**lm_coords_finder(char **map, t_xy size, t_landmarks lm)
{
	char	**lm_coords;
	int	i;


	lm_coords = malloc(sizeof(char*) * lm.total);
	i = 0;
	while (i < lm.total)
		lm_coords[i++] = malloc(sizeof(char) * 4);
	lm_coords = lm_coords_filler(map, size, lm_coords);
	//lm_coords_printer(lm_coords, lm);
	return(lm_coords);
}

t_landmarks	landmark_test (char **map, t_xy size)
{
	t_xy	b;
	t_landmarks	lm;

	b = xy_initializer();
	lm = lm_initializer();
	while (b.y < size.y)
	{
		while (b.x < size.x)
		{
			if (map[b.x][b.y] == 'P')
				lm.p++;
			if (map[b.x][b.y] == 'E')
				lm.e++;
			if (map[b.x][b.y] == 'C')
				lm.c++;
			if (map[b.x][b.y] == 'V')
				lm.v++;
			b.x++;
		}
		b.x = 0;
		b.y++;
	}
	if (lm.p == 1 && lm.e == 1 && lm.c >= 1 &&  lm.v >= 0)
		lm.total = lm.p + lm.e + lm.c + lm.v;
	else
		lm.total = -1;
	return (lm);
}

int	outer_wall_test(int x_or_y, int val, char **map, t_xy size)
{
	int	walls;
	t_xy	b;

	b = xy_initializer();
	walls = 0;
	if (x_or_y == 'x')
	{
		while (b.y < size.y)
		{
			if (map[b.y][val] == '1')
				walls++;
			b.y++;
		}
		if (walls == size.y)
			return (1);
	}
	if (x_or_y == 'y')
	{
		while (b.x < size.x)
		{
			if (map[val][b.x] == '1')
				walls++;
			b.x++;
		}
		if (walls == size.x)
			return (1);
	}
	return (-1);
}


int	box_walls_test(char **map, t_xy size)
{
	if (outer_wall_test('x', 0, map, size) == -1)
		return (-1);
	else if (outer_wall_test('x', size.x - 1, map, size) == -1)
		return (-1);
	else if (outer_wall_test('y', 0, map, size) == -1)
		return (-1);
	else if (outer_wall_test('y', size.y - 1, map, size) == -1)
		return (-1);
	return (1);
}


int	blocks_test (char **map, t_xy size)
{
	t_xy	b;

	b = xy_initializer();
	while (b.y < size.y)
	{
		while (b.x < size.x)
		{
			if(map[b.x][b.y] == 'P' || map[b.x][b.y] == 'E' || map[b.x][b.y] == 'C' /*|| map[b.x][b.y] == 'V'*/ || map[b.x][b.y] == '0' || map[b.x][b.y] == '1')
				b.x++;
			else
				return (-1);
		}
		b.x = 0;
		b.y++;
	}
	return (1);
}



int	path_test (char **lm_coords, t_landmarks lm, t_walk_list *wl)
{
	t_walk_list	*aux;
	int	i;
	int	total;

	aux = wl;
	i = 0;
	total = 0;
	while (lm_coords[i])
	{
		while (aux)
		{
			if (aux->x == lm_coords[i][0] && aux->y == lm_coords[i][1])
			{
				//ft_printf("FOUND (%d, %d)\n", aux->x, aux->y);
				total++;
			}
			aux = aux->next;
		}
		aux = wl;
		i++;
	}
	if (total == lm.total)
		return (1);
	return (-1);
}


//ENDING &/OR ERROR FUNCTIONS

/*void	map_freer(char **map)
{
	int	y;
	
	y = 0;
	while (y < 8)
		free(map[y++]);
	free(map);
}*/

/*t_xy	size_test(char **map)
{
	t_xy	size;
	int	first_x;

	size = xy_initializer();
	first_x = 0;
	while (map[0][first_x])
		first_x++;
	while (map[size.y])
	{
		while (map[size.y][size.x] != '\0')
		{
			size.x++;
			ft_test_printf("%d %d\n\n", size.x, size.y);	
		}
		if (size.x != first_x)
		{
			size.x = -1;
			return (size);
		}
		size.x = 0;
		size.y++;
	}
	return (size);
}*/

//UNEXPECTED SEGFAULT: NEEDS TO BE FIXED


//-----

//int argc, char **argv

int	main()
{
	char	**map = NULL;
	t_xy	size;
	t_landmarks	lm;
	char **lm_coords = NULL;
	t_walk_list	*wl;

	wl = NULL;
	map = malloc(sizeof(char *) * 8);
	map[0] = "1111111";
	map[1] = "1E0C001";
	map[2] = "1111101";
	map[3] = "100P0C1";
	map[4] = "1011111";
	map[5] = "100C0C1";
	map[6] = "1111111";
	map[7] = "\0";
	ft_test_printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n\n", map[0], map[1], map[2], map[3], map[4], map[5], map[6]);
	//size = size_test(map);
	size.x = 7;
	size.y = 7;
	ft_test_printf("size = (%d, %d)\n\n", size.x, size.y);
	if (size.x == -1)
		return (-1);
	if (blocks_test(map, size) == -1)
	{
		ft_test_printf("blocks_test failed\n");
		return (-1);
	}
	else
		ft_test_printf("blocks_test passed\n");
	if (box_walls_test(map, size) == -1)
	{
		ft_test_printf("box_walls_test failed\n");
		return (-1);
	}
	else
		ft_test_printf("box_walls_test passed\n");
	lm = landmark_test(map, size);
	if (lm.total == -1)
	{
		ft_test_printf("landmark_test failed\n");
		return (-1);
	}
	else
		ft_test_printf("landmark_test passed, lm.total = %d\n", lm.total);
	lm_coords = lm_coords_finder(map, size, lm);
	ft_add_node(&wl, lm_coords[0][0], lm_coords[0][1], 0);
	list_maker(wl, map, size);
	if (path_test (lm_coords, lm, wl) == -1)
	{
		ft_test_printf("path_test failed\n");
		return (-1);
	}
	else
		ft_test_printf("path_test passed\n");
	/*mlx_window = mlx_new_window(mlx, (size.x - 1) * 64, (size.y - 1) * 64, "so_long");
	img.img = mlx_new_image(mlx, (size.x - 1) * 64, (size.y - 1) * 64);*/
	return (1);
}
