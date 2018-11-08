#include "wolf.h"

static int		ft_destroy_key(t_data *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int				deal_key(int key, void *param)
{
	if (key != 82 && key != 83 && key != 84 && key != 85 && key != 86 &&
		key != 87 && key != 88 && key != 89 && key != 91 && key != 53 &&
		key != 92 && key != 69 && key != 78 && key != 126 && key != 125 &&
		key != 40 && key != 124 && key != 123)
		return (0);
	if (key == ESC)
		ft_destroy_key(((t_data *)param));
    return (0);
}