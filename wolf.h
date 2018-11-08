#ifndef WOLF_H
# define WOLF_H

# include <mlx.h>
# include "libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "/Users/tlaberro/goinfre/FMOD/api/lowlevel/inc/fmod.h"

# define A 0
# define B 11
# define C 8
# define D 2
# define E 4
# define F 3
# define G 9
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6

# define PAD_ONE 83
# define PAD_TWO 84
# define PAD_THREE 85
# define PAD_FOUR 86
# define PAD_FIVE 87
# define PAD_SIX 88
# define PAD_SEVEN 89
# define PAD_EIGHT 91
# define PAD_NINE 92

# define LESS 78
# define MORE 69

# define DOWN_ARROW 125
# define UP_ARROW 126

# define SPACEBAR 49
# define ESC 53

typedef struct		s_pixel
{
	int x;
	int y;
	int z;
}                   t_pixel;

typedef struct          s_data
{
    //void
    void	*mlx_ptr;
	void	*win_ptr;
    void	*img_ptr;
    //int
    int     l;
    int     j;
    int     fd;
    int     ligne;
    int     colonne;
    int		xdecale;
	int		ydecale;
    int		bpp;
	int		s_l;
	int		endian;
    int		high;
	int		width;
    //t_pixel
    t_pixel     **tab_int;
    //char **
    char **test;
    //char
    char	*img;

}                       t_data;

int				ft_get_tab(char *argv, t_data *data);
void			ft_exit(int fd);
void        ft_struct(t_data *data);
void			ft_chartoint(char *argv, t_data *data);
void			ft_exitgetnbrcolonne(int fd);
void        ft_verif_file(t_data *data, char *argv);
void		wolf(t_data *data);
void		image_set_pixel(t_data *data, int x, int y, int color);
void		new_image(t_data *data);
int				deal_key(int key, void *param);
int         ft_close(t_data *data);
int		deal_mouse(int key, int x, int y, void *param);











#endif