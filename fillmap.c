/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillmap.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:37:44 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 13:51:53 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* FillIt
1. Call the fill_map function
2. If the fill_map function does not successfully place all pieces within the map, make map size bigger by 1 and try again
3. Once fill_map is complete, return the valid map
*/

char  **fill_it(char **map, tetromino_data saved_coordinates[26], int map_size, int num_of_tets, int struct_counter)
{
	while (fill_map(map, saved_coordinates, map_size, num_of_tets, struct_counter) == 0)
	{
		free(map);
		map_size++;
		map = make_map(map_size);
		struct_counter = 0;
	}
	return (map);
}

/*
1. Find open space, if all pieces fit, place them. Call the find_open_space function again until all tetrominos are filled
2. If a piece doesn't fit, remove the previous piece and place it in a new spot, try again
3. If there is no solution then return 0 and make map_size bigger by 1
*/

int fill_map(char **map, tetromino_data saved_coordinates[26], int map_size, int num_of_tets, int struct_counter)
{
	int x = 0;
	int y = 0;
	int temp_x = 0;
	int temp_y = 0;

	if (struct_counter == num_of_tets)
		return (1);
	while (x < map_size)
	{
		while (y < map_size)
		{
			if (map[x][y] == '.')
			{
				temp_x = x;
				temp_y = y;
				if (find_open_space(map, saved_coordinates, temp_x, temp_y, map_size, 0, struct_counter) == 4)
    			{
					map = place_pieces(map, saved_coordinates, temp_x, temp_y, 0, struct_counter);
					if (!(fill_map(map, saved_coordinates, map_size, num_of_tets, struct_counter + 1) == 1))
						map = remove_pieces(map, saved_coordinates, temp_x, temp_y, 3, struct_counter);
					else	
						return (1);
				}
			}
			y++;
		}
		x++;
		y = 0;
	}
return (0);
}

/*
1. Checks if all the pieces that may be placed are within the map's parameters
2. Then checks if all the pieces that may be placed have open spots '.'
*/

int find_open_space(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int map_size, int open_space_count, int struct_counter)
{	
	int out_of_bounds_counter = 1;
	int replacement_map = map_size - 1;

	while (out_of_bounds_counter != 4)
	{
		if ((saved_coordinates[struct_counter].x[out_of_bounds_counter] + temp_x >= 0) && (saved_coordinates[struct_counter].y[out_of_bounds_counter] + temp_y >= 0)
		&& (saved_coordinates[struct_counter].x[out_of_bounds_counter] + temp_x <= replacement_map) && (saved_coordinates[struct_counter].y[out_of_bounds_counter] + temp_y <= replacement_map))
			out_of_bounds_counter++;
		else
			return (open_space_count);
	}
	while (open_space_count != 4)
	{
		if (map[saved_coordinates[struct_counter].x[open_space_count] + temp_x][saved_coordinates[struct_counter].y[open_space_count] + temp_y] == '.')
			open_space_count++;
		else
			return (open_space_count);
	}
	return (open_space_count);
}

/*
1. Place all pieces on the map according to their letter value
*/

char **place_pieces(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int open_space_count, int struct_counter)
{
	while (open_space_count != 4)
	{
		map[saved_coordinates[struct_counter].x[open_space_count] + temp_x][saved_coordinates[struct_counter].y[open_space_count] + temp_y] = saved_coordinates[struct_counter].letter;
		open_space_count++; 
	}
	print_final_map(map);
	printf("\n");
	return (map);
}

/*
1. Remove pieces by substituing '.' in their coordinates
*/

char **remove_pieces(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int open_space_count, int struct_counter)
{
	while (open_space_count != -1)
	{
		(map[saved_coordinates[struct_counter].x[open_space_count] + temp_x][saved_coordinates[struct_counter].y[open_space_count] + temp_y] = '.');
		open_space_count--;
	}
	return (map);
}