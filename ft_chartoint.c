#include "wolf.h"

static void		ft_supportchartoint(t_data *data, int i, int h)
{
	data->tab_int[h][i].z = ft_atoi(data->test[i]);
	data->tab_int[h][i].x = data->xdecale;
	data->tab_int[h][i].y = data->ydecale;
	free(data->test[i]);
}

static void		ft_supportchartoint2(t_data *data, int i)
{
	free(data->test[i]);
	free(data->test);
}

void			ft_chartoint(char *argv, t_data *data)
{
	char	*line;
	int		i;
	int		h;

	i = 0;
	h = 0;
	data->fd = open(argv, O_RDONLY);
	while (get_next_line(data->fd, &line) == 1)
	{
		data->test = ft_strsplit(line, ' ');
		while (i < data->colonne)
		{
			ft_supportchartoint(data, i, h);
			i++;
			data->xdecale = data->xdecale;// + data->space;
		}
		ft_supportchartoint2(data, i);
		i = 0;
		data->xdecale = 0;
		data->ydecale = data->ydecale;// + data->space;
		h++;
		free(line);
	}
	free(line);
	close(data->fd);
}

void			ft_delete(t_data *data)
{
	int i;

	i = 0;
	while (i < data->ligne)
	{
		free(data->tab_int[i]);
		i++;
	}
}