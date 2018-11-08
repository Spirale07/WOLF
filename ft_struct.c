#include "wolf.h"

void        ft_struct(t_data *data)
{
    data->mlx_ptr = NULL;
	data->win_ptr = NULL;
    data->tab_int = NULL;
    data->img_ptr = NULL;
	data->img = NULL;
	data->colonne = 0;
	data->ligne = 0;
    data->j = 0;
	data->l = 0;
    data->fd = 0;
    data->xdecale = 0;
	data->ydecale = 0;
    data->test = NULL; // a verif
    data->bpp = 0;
	data->s_l = 0;
	data->endian = 0;
    data->width = 1000;
	data->high = 1000;
}