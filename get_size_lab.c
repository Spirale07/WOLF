#include "wolf.h"

void			ft_exitgetnbrcolonne(int fd)
{
	ft_putendl("La map n'est pas valide.");
	ft_exit(fd);
}

static int		ft_wordcount(const char *str, char c)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			len++;
		}
		i++;
	}
	if (len == 0)
		exit(EXIT_FAILURE);
	if (str[i - 1] != c)
		return (len + 1);
	else
		return (len);
}

static int		ft_get_nbr_ligne(char *argv, char *line)
{
	int fd;
	int i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		free(line);
		i++;
	}
	free(line);
	close(fd);
	return (i);
}

void			ft_exit(int fd)
{
	close(fd);
	exit(EXIT_FAILURE);
}

static int		ft_get_nbr_colonne(char *argv, char *line, t_data *data)
{
	int			fd;
	static int	tailleall = 0;

	fd = open(argv, O_RDONLY);
	if (fd > 0)
	{
		while (get_next_line(fd, &line) == 1)
		{
			data->l = ft_wordcount(line, ' ');
			if (data->j == 0)
				tailleall = data->l;
			data->j++;
			if (data->j != 0)
				if (tailleall != data->l)
					ft_exitgetnbrcolonne(fd);
			free(line);
		}
		free(line);
		close(fd);
	}
	else
		ft_exit(fd);
	return (tailleall);
}

int				ft_get_tab(char *argv, t_data *data)
{
	char		*line;
	int			i;
	t_pixel		**ptr;

	line = NULL;
	i = 0;
	data->ligne = ft_get_nbr_ligne(argv, line);
	data->colonne = ft_get_nbr_colonne(argv, line, data);
	if (data->ligne == 0 && data->colonne == 0)
		exit(EXIT_FAILURE);
	if (data->colonne == -1)
		return (-1);
	ptr = data->tab_int;
	data->tab_int = (t_pixel **)malloc(sizeof(t_pixel *) * data->ligne);
	free(ptr);
	while (i < data->ligne)
	{
		data->tab_int[i] = (t_pixel *)malloc(data->colonne * sizeof(t_pixel));
		i++;
	}
	return (0);
}