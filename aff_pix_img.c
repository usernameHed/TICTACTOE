/*
** aff_pix_img.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 16:36:46 2014 ugo belfiore
** Last update Mon Nov  3 01:57:13 2014 ugo belfiore
*/

#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

int	aff_line(t_data data, int x1, int y1, int x2, int y2);

int	aff_pix_img(t_data d, int x, int y)
{
  int	i;

  if (d.endian == 0)
    {
      i = (d.sizeline * y) + (x * (d.bpp / 8));
      d.bigData[i] = mlx_get_color_value(d.mlx_ptr, d.colo);
      d.bigData[i + 1] = mlx_get_color_value(d.mlx_ptr, d.colo >> 8);
      d.bigData[i + 2] = mlx_get_color_value(d.mlx_ptr, d.colo >> 16);
    }
  else
    {
      i = (d.sizeline * y) + (x * (d.bpp / 8));
      d.bigData[i] = mlx_get_color_value(d.mlx_ptr, d.colo >> 16);
      d.bigData[i + 1] = mlx_get_color_value(d.mlx_ptr, d.colo >> 8);
      d.bigData[i + 2] = mlx_get_color_value(d.mlx_ptr, d.colo);
    }
  return (0);
}

t_data	aff_win_img(t_data d)
{
  int	i;
  int	a;

  i = 0;
  while (i != d.sizeline * d.y_max)
    {
      d.bigData[i++] = 255;
      d.bigData[i++] = 255;
      d.bigData[i++] = 0;
      d.bigData[i++] = 0;
    }
  i = 0;
  a = 0;
  d.colo = 0x00111111;
  while (i < 152)
    {
      aff_line(d, 0, a, d.x_max, a);
      aff_line(d, a, 0, a, d.y_max);
      a++;
      if (a == 38 || a == 226 || a == 414)
	a+= 150;
      i++;
    }
  i = 0;
  while (i < 9)
    {
      d.tab[i] = 0;
      i++;
    }
  return (d);
}

/* int	print_xpm(t_point *pt, char *xpm, int x, int y) */
/* { */
/*   pt->img = mlx_xpm_file_to_image(pt->mlx_ptr, */
/*                                   xpm, &(pt->width), &(pt->height)); */
/*   mlx_put_image_to_window(pt->mlx_ptr, pt->win_ptr, pt->img, x, y); */
/*   return (0); */
/* } */
