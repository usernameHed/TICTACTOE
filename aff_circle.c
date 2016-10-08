/*
** aff_circle.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Fri Oct 31 10:39:41 2014 ugo belfiore
** Last update Sat Nov  1 18:11:30 2014 ugo belfiore
*/

#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

t_circle	aff_circleBIS(t_circle c);
int		aff_pix_img(t_data d, int x, int y);

int		aff_circle(t_data d, int x, int y, int r)
{
  t_circle	c;

  c.x_mid = x;
  c.y_mid = y;
  c.x = 0;
  c.y = r;
  c.r = r;
  c.di = r - 1;
  while (c.y >= c.x)
    {
      aff_pix_img(d, c.x_mid + c.x, c.y_mid + c.y);
      aff_pix_img(d, c.x_mid + c.y, c.y_mid + c.x);
      aff_pix_img(d, c.x_mid - c.x, c.y_mid + c.y);
      aff_pix_img(d, c.x_mid - c.y, c.y_mid + c.x);
      aff_pix_img(d, c.x_mid + c.x, c.y_mid - c.y);
      aff_pix_img(d, c.x_mid + c.y, c.y_mid - c.x);
      aff_pix_img(d, c.x_mid - c.x, c.y_mid - c.y);
      aff_pix_img(d, c.x_mid - c.y, c.y_mid - c.x);
      c = aff_circleBIS(c);
    }
  return (0);
}

t_circle	aff_circleBIS(t_circle c)
{
  if (c.di >= (2 * c.x))
    {
      c.di = c.di - (2 * c.x) - 1;
      c.x++;
    }
  else if (c.di < 2 * (c.r - c.y))
    {
      c.di =  c.di + (2 * c.y) - 1;
      c.y--;
    }
  else
    {
      c.di = c.di + 2 * (c.y - c.x - 1);
      c.y = c.y - 1;
      c.x = c.x + 1;
    }
  return (c);
}
