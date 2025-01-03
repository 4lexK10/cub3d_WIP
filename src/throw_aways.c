#include "cub3d.h"

void	print_player(t_player *player, char *msg)
{
	printf("player at %s\n", msg);
	//printf("pos[X] = %f pos[Y] = %f\n", player->pos[X] , player->pos[Y]);
	printf("dir[X] = %f dir[Y] = %f\n", player->dir[X] , player->dir[Y]);
	printf("plane [X] = %f plane [Y] = %f\n", player->plane[X] , player->plane[Y]);
}
