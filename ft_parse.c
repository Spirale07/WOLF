#include "wolf.h"

void        ft_verif_file(t_data *data, char *argv)
{
    int i = 0;
    char *line = NULL;
    int fd;

    fd = open(argv, O_RDONLY);
    ft_putnbr(fd);
    ft_putchar('\n');
    if (fd > 0)
    {
        while (get_next_line(fd, &line) == 1)
        {
                if (line[i] != '1' && line[i] != '0' && line[i] != '\n' &&
                    line[i] != ' ' && line[i] != '\0')
                {
                    ft_putendl("La map doit etre composee de 1 et de 0.");
                    free(line);
                    ft_exit(fd);
                }
                i++;
                //free(line);
        }
        free(line);
        close(fd);
    }
    else
    {   
        ft_putendl("./wolf3d map");
        ft_exit(fd);
    }
}