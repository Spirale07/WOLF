#include "wolf.h"

int         ft_close(t_data *data)
{
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int         main(int argc, char **argv)
{
    t_data  *data;
    int h = 0;
    int i = 0;

    if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (-1);
    ft_struct(data);
    ft_verif_file(data, argv[1]);
    if ((data->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
    wolf(data);
    if (argc == 2)
    {
        ft_get_tab(argv[1], data);
        ft_chartoint(argv[1], data);


        mlx_key_hook(data->win_ptr, deal_key, data);
	    mlx_hook(data->win_ptr, 17, 1L << 17, ft_close, data);
	    mlx_loop(data->mlx_ptr);

    }
    return(0);
}



//mlx_hook(data->win_ptr, 17, (1L << 6), close, data);









//test affich map

/*        while (h < data->ligne)
        {
            while (i < data->colonne)
            {
                ft_putnbr(data->tab_int[h][i].z);
                ft_putchar (' ');
                i++;
            }
            ft_putchar('\n');
            i = 0;
            h++;
        }
        */