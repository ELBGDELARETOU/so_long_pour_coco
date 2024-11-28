/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:05:26 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/27 12:11:59 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct slg
{
	int		m_i;
	int		m_c;
	char	*str;
	char	*tmp_bis;
	int		mooves_counter;
	char	*line;
	char	*map;
	char	*tmp;
	int		fd;
	int		backslash_n_count;
	int		e_count;
	int		p_count;
	int		c_count;
	int		actual_c_counter;
	int		player_x;
	int		player_y;
	void	*mlx;
	char	**rectangle;
	char	**rectangle_copy;
	int		number_of_lines;
	int		len_of_lines;
	void	*img_floor;
	void	*img_top;
	void	*img_corner_left;
	void	*img_corner_right;
	void	*img_bottom_corner_right;
	void	*img_bottom_corner_left;
	void	*img_bottom;
	void	*img_long_wall_right;
	void	*img_long_wall_left;
	void	*img_white_right_corner;
	void	*img_white_left_corner;
	void	*img_white_bottom_left;
	void	*img_white_bottom_right;
	void	*img_white_top;
	void	*img_white_bottom;
	void	*img_white_left;
	void	*img_white_right;
	void	*key[4];
	void	*door1;
	void	*door2;
	void	*hero[4];
	void	*stairs;
	void	*img_interior_walls;
	char	*path;
	int		img_width;
	int		img_height;
	void	*mlx_win;
	int		x;
	int		y;
	int		total_len;
	int		total_height;
}			t_slg;

int			closer(t_slg *slg);

// fontion de convertion d image
int			convert_all_images(t_slg *slg);
int			convert_img(t_slg *slg);
int			convert_img2(t_slg *slg);
int			convert_img3(t_slg *slg);
int			convert_img4(t_slg *slg);
int			convert_img5(t_slg *slg);
void		init_img(t_slg *slg);

// fonction de verification de map
int			count_line(char *map);
int			check_walls(char **map, int number_of_lines, int len_of_lines);
int			check_map(char *map, t_slg *slg);
int			ft_strlen_of_one_line(char *str);
int			check_rectangle(char *map, t_slg *slg);
int			check_all(char *map, t_slg *slg);
int			check(t_slg *slg, char *argv);
int			check_if_map_is_possible(t_slg *slg);

// fonciton d'initialisation de la map de base
int			create_base_map(t_slg *slg);
int			init_base(t_slg *slg);
void		init_background(t_slg *slg);
void		init_walls(t_slg *slg);
void		init_white_walls(t_slg *slg);
void		init_corner(t_slg *slg);
void		init_white_corners(t_slg *slg);
int			ft_strlen_of_one_line(char *str);

// fonction handle mooves
int			handle_w(t_slg *slg);
int			handle_a(t_slg *slg);
int			handle_d(t_slg *slg);
int			handle_s(t_slg *slg);
int			key_pressed(t_slg *slg);
int			key_press(int key, t_slg *slg);

// fonction d_initialisation map
void		init_background(t_slg *slg);
void		init_walls(t_slg *slg);
void		init_white_walls(t_slg *slg);
void		init_corner(t_slg *slg);
void		init_white_corners(t_slg *slg);

// fonction d initialisation reste
void		init_interior_walls(t_slg *slg);
void		init_exit(t_slg *slg);
void		init_colectible(t_slg *slg);
int			init_hero(t_slg *slg);
int			colectible(t_slg *slg);

// fonction de destroy/clean
void		destroy_image(t_slg *slg);
void		destroy_image2(t_slg *slg);
void		destroy_image3(t_slg *slg);
void		destroy_image4(t_slg *slg);
void		destroy_image5(t_slg *slg);
void		free_double_tab(char **tab);
int			closer(t_slg *slg);
void		free_double_tab(char **tab);

//gestion des mouvements
int			key_press(int key, t_slg *slg);
void		path_flood(t_slg *slg, int x, int y);

#endif