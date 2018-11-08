#include "wolf.h"

void		wolf(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->width, data->high, "Wolf");
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->width,
			data->high);
	data->img = mlx_get_data_addr(data->img_ptr,
			&(data->bpp), &(data->s_l), &(data->endian));
}

void		image_set_pixel(t_data *data, int x, int y, int color)
{
	if (x < 0 || x >= data->width || y < 0 || y >= data->high)
		return ;
	*((int*)(data->img + ((x + y * data->width) * 4))) = color;
}

void		new_image(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);

	mlx_put_image_to_window(data, data->win_ptr, data->img_ptr, 0, 0);
}
