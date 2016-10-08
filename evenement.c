/*
** evenement.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 15:43:22 2014 ugo belfiore
** Last update Wed Nov  5 14:03:33 2014 ugo belfiore
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

t_data	aff_win_img(t_data d);
t_data	tab_test(t_data d, int x, int y);
t_data	test_win(t_data d);

int		manage_key(int keycode, void *param)
{
  t_data	*d;

  d = (t_data *)param;
  my_put_nbr(keycode);
  my_putchar(10);
    if (keycode == KEY_KILL)
      {
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	exit(0);
      }
  if (keycode == KEY_REFRESH)
    {
      *d = aff_win_img(*d);
      mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
    }
  if (keycode == KEY_ESC)
    exit(0);
  return (0);
}

int		manage_mouse(int button, int x, int y, void *param)
{
  t_data	*data;

  data = (t_data *)param;
  my_put_nbr(x);
  my_putchar(':');
  my_put_nbr(y);
  my_putchar(':');
  my_put_nbr(button);
  my_putchar(10);
  data->colo = 0x00FF0000;
  *data = tab_test(*data, x, y);
  *data = test_win(*data);
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  return (0);
}

int		manage_expose(void *param)
{
  t_data	*data;

  data = (t_data *)param;
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  return (0);
}

int             aff_win(char *name, int x_max, int y_max)
{
  t_data        d;
  int		i;

  d.x_max = x_max;
  d.y_max = y_max;
  d.mlx_ptr = mlx_init();
  d.win_ptr = mlx_new_window(d.mlx_ptr, x_max, y_max, name);
  //// IMAGE
  while (i < 9)
    {
      d.tab[i] = 0;
      i++;
    }
  d.player = 1;
  d.img_ptr = mlx_new_image(d.mlx_ptr, x_max, y_max);
  d.bigData = mlx_get_data_addr(d.img_ptr, &d.bpp, &d.sizeline, &d.endian);
  d = aff_win_img(d);
  mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img_ptr, 0, 0);
  mlx_key_hook(d.win_ptr, &manage_key, (void *)(&d));
  mlx_mouse_hook(d.win_ptr, &manage_mouse, (void *)(&d));
  mlx_expose_hook(d.win_ptr, &manage_expose, (void *)(&d));
  mlx_loop(d.mlx_ptr);
  return (0);
}
