/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:42:01 by anaouali          #+#    #+#             */
/*   Updated: 2024/02/26 18:26:56 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int key, t_slg *slg)
{
	colectible(slg);
	if (key == XK_Escape)
		closer(slg);
	else if (key == XK_w && (!handle_w(slg)))
		return (-1);
	else if (key == XK_a && (!handle_a(slg)))
		return (-1);
	else if (key == XK_d && (!handle_d(slg)))
		return (-1);
	else if (key == XK_s && (!handle_s(slg)))
		return (-1);
	if (key == XK_w || key == XK_a || key == XK_d || key == XK_s)
	{
		mlx_put_image_to_window(slg->mlx, slg->mlx_win, slg->img_corner_left,
			0, 0);
		slg->str = ft_itoa(slg->mooves_counter);
		slg->tmp_bis = ft_strjoin("moves : ", slg->str);
		mlx_string_put(slg->mlx, slg->mlx_win, 10, 10, 0xFF0000, slg->tmp_bis);
		free(slg->tmp_bis);
		free(slg->str);
		key_pressed(slg);
		return (0);
	}
	return (-1);
}
