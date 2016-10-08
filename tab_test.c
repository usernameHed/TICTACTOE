/*
** tab_test.c for  in /home/belfio_u/rendu/EXOTEST/TICTACTOE
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Mon Nov  3 01:44:06 2014 ugo belfiore
** Last update Mon Nov  3 12:24:59 2014 ugo belfiore
*/

#include "./minilibx/mlx.h"
#include "./include/mini.h"
#include "./include/my.h"

int	aff_line(t_data data, int x1, int y1, int x2, int y2);
int	aff_circle(t_data data, int x, int y, int r);
int	cross(t_data d, int x, int y);
int	circle(t_data d, int x, int y);
t_data	line_win(t_data d, int a);

t_data	tab_test(t_data data, int x, int y)
{
  if ( x > 38 && x < 188 && y > 38 && y < 188 && data.tab[0] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 113, 113);
	  data.tab[0] = 1;
	}
      else
	{
	  circle(data, 113, 113);
	  data.tab[0] = 2;
	}
      data.player *= -1;
    }
  if (x > 226 && x < 376 && y > 38 && y < 188 && data.tab[1] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 301, 113);
	  data.tab[1] = 1;
	}
      else
	{
	  circle(data, 301, 113);
	  data.tab[1] = 2;
	}
      data.player *= -1;
    }
  if (x > 414 && x < 565 && y > 38 && y < 188 && data.tab[2] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 489, 113);
	  data.tab[2] = 1;
	}
      else
	{
	  circle(data, 489, 113);
	  data.tab[2] = 2;
	}
      data.player *= -1;
    }
  if ( x > 38 && x < 188 && y > 226 && y < 376 && data.tab[3] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 113, 301);
	  data.tab[3] = 1;
	}
      else
	{
	  circle(data, 113, 301);
	  data.tab[3] = 2;
	}
      data.player *= -1;
    }
  if ( x > 226 && x < 376 && y > 226 && y < 376 && data.tab[4] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 301, 301);
	  data.tab[4] = 1;
	}
      else
	{
	  circle(data, 301, 301);
	  data.tab[4] = 2;
	}
      data.player *= -1;
    }
  if ( x > 414 && x < 564 && y > 226 && y < 376 && data.tab[5] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 489, 301);
	  data.tab[5] = 1;
	}
      else
	{
	  circle(data, 489, 301);
	  data.tab[5] = 2;
	}
      data.player *= -1;
    }
  if ( x > 38 && x < 188 && y > 414 && y < 564 && data.tab[6] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 113, 489);
	  data.tab[6] = 1;
	}
      else
	{
	  circle(data, 113, 489);
	  data.tab[6] = 2;
	}
      data.player *= -1;
    }
  if ( x > 226 && x < 376 && y > 414 && y < 564 && data.tab[7] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 301, 489);
	  data.tab[7] = 1;
	}
      else
	{
	  circle(data, 301, 489);
	  data.tab[7] = 2;
	}
      data.player *= -1;
    }
  if ( x > 414 && x < 564 && y > 414 && y < 564 && data.tab[8] == 0)
    {
      if (data.player == 1)
	{
	  cross(data, 489, 489);
	  data.tab[8] = 1;
	}
      else
	{
	  circle(data, 489, 489);
	  data.tab[8] = 2;
	}
      data.player *= -1;
    }
  return (data);
}

t_data	test_win(t_data d)
{
  int	i;

  i = 1;
  while (i <= 2)
    {
      if (d.tab[0] == i && d.tab[1] == i && d.tab[2] == i)
	d = line_win(d, 1);
      if (d.tab[3] == i && d.tab[4] == i && d.tab[5] == i)
	d = line_win(d, 2);
      if (d.tab[6] == i && d.tab[7] == i && d.tab[8] == i)
	d = line_win(d, 3);
      
      if (d.tab[0] == i && d.tab[3] == i && d.tab[6] == i)
	d = line_win(d, 4);
      if (d.tab[1] == i && d.tab[4] == i && d.tab[7] == i)
	d = line_win(d, 5);
      if (d.tab[2] == i && d.tab[5] == i && d.tab[8] == i)
	d = line_win(d, 6);
      
      if (d.tab[0] == i && d.tab[4] == i && d.tab[8] == i)
	d = line_win(d, 7);
      if (d.tab[6] == i && d.tab[4] == i && d.tab[2] == i)
	d = line_win(d, 8);
      i++;
    }
  return (d);
}

t_data	line_win(t_data d, int a)
{
  int	i;

  i = 0;
  d.colo = 0x00111111;
  if (a <= 3)
    {
      while (i < 10)
	{
	  aff_line(d, 113, (187 * (a - 1)) + (113 + i), 489,
		   (187 * (a - 1)) + (113 + i));
	  i++;
	}
    }
  else if (a > 3 && a <= 6)
    {
      while (i < 10)
	{
	  aff_line(d, (188 * (a - 1)) + (147 + i), 113,
		   (188 * (a - 1)) + (147 + i), 498);
	  i++;
	}
    }
  else if (a == 7)
    {
      while (i < 10)
	{
	  aff_line(d, 113 + i, 113, 489 + i, 489);
	  i++;
	}
    }
  else
    {
      while (i < 10)
	{
	  aff_line(d, 489 + i, 113, 113 + i, 489);
	  i++;
	}
    }
  i = 0;
  while (i < 9)
    {
      d.tab[i] = 3;
      i++;
    }
  return (d);
}

int     cross(t_data d, int x, int y)
{
  int   i;
  int	j;

  i = 0;
  j = 10;
  while (i < 10)
    {
      aff_line(d, x - 60, y - 60 + i, x + 50 + j, y + 50 + i + j);
      aff_line(d, x + 60, y - 60 + i, x - 50 - j, y - 50 + i - j);
      aff_line(d, x + 60, y - 60 + i, x - 50 + j, y + 50 - i + j);
      i++;
      j--;
    }
  return (0);
}

int     circle(t_data d, int x, int y)
{
  int   i;

  i = 0;
  while (i < 60)
    {
      aff_circle(d, x, y, i);
      i++;
    }
  return (0);
}
