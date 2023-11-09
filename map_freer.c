#include "so_long.h"

void    map_freer(t_game *game)
{
    int y;
    y = 0;
    while(y < game->size.y)
    {
        free(game->map[y]);
        y++;
    }
    free(game->map[game->size.y]);
}