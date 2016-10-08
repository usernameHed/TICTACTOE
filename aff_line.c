/*
** useful_fonc.c for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 15:50:41 2014 ugo belfiore
** Last update Thu Oct 30 15:42:37 2014 ugo belfiore
*/

#include <stdlib.h>
#include "./minilibx/mlx.h"
#include "./include/my.h"
#include "./include/mini.h"

int	aff_line_verti(t_data d, t_line a);
int	aff_line_horiz(t_data d, t_line a);
int	aff_lineBIS(t_data d, t_line a);

int		aff_line(t_data d, int x1, int y1, int x2, int y2)
{
  t_line	a;

  a.x1 = x1;
  a.x2 = x2;
  a.y1 = y1;
  a.y2 = y2;
  a.dx = a.x2 - a.x1;
  a.dy = a.y2 - a.y1;
  if (a.dx == 0)
    {
      aff_line_verti(d, a);
    }
  else
    {
      if (a.dy == 0)
	aff_line_horiz(d, a);
      else
	aff_lineBIS(d, a);
    }
  return (0);
}
