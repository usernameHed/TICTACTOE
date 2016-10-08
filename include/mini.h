/*
** mini.h for  in /home/belfio_u/rendu/EXOTEST/FDF
** 
** Made by ugo belfiore
** Login   <belfio_u@epitech.net>
** 
** Started on  Tue Oct 28 09:26:37 2014 ugo belfiore
** Last update Mon Nov  3 01:52:43 2014 ugo belfiore
*/

#ifndef MINI_H_
#define MINI_H_

#define COLOR_BLUE 0x0000FF
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLACK 0xFFFFFF
#define COLOR_WHITE 0x000000
#define KEY_ENTER 65293
#define KEY_ESC 65307
#define KEY_REFRESH 114
#define KEY_KILL 107

typedef struct	s_data
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*bigData;
  int		x;
  int		y;
  int		x_max;
  int		y_max;
  int		colo;
  int		bpp;
  int		sizeline;
  int		endian;
  int		tab[9];
  int		player;
}               t_data;

typedef struct	s_line
{
  int		dx;
  int		dy;
  int		e;
  int		x1;
  int		x2;
  int		y1;
  int		y2;
}		t_line;

typedef struct	s_circle
{
  int		x_mid;
  int		y_mid;
  int		x;
  int		y;
  int		r;
  int		di;
}		t_circle;

#endif
