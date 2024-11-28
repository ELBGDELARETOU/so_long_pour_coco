/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaouali <anaouali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:15:03 by anaouali          #+#    #+#             */
/*   Updated: 2024/06/07 16:48:21 by anaouali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv, char **env)
{
	t_slg	slg;

	if (!env[0])
		return (-1);
	if (argc == 2)
	{
		ft_memset(&slg, 0, sizeof(t_slg));
		if (check(&slg, argv[1]) == -1)
			return (-1);
		if (create_base_map(&slg) == -1)
			return (-1);
		mlx_key_hook(slg.mlx_win, &key_press, &slg);
		mlx_hook(slg.mlx_win, 17, 0, &closer, &slg);
		mlx_loop(slg.mlx);
	}
	else
		ft_putstr_fd("ERROR SYNTAX\nExemple : ./so_long path/of/map.ber\n", 1);
	return (-1);
}
