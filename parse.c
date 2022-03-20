/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:37:44 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 13:51:53 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Parse Function
1. Validate if tetrominos are correctly inputted
2. Save coordinates of the tetrominos into 2-dimensional array structures
3. Fill map using recursion
4. Print final map
*/

int parse(char *file)
{
	int file_descriptor = open(file, O_RDONLY);
	char buffer[545];
	int bytes = read(file_descriptor, buffer, 545);
	close(file_descriptor);
	buffer[bytes] = '\0';

	int num_of_tets = find_tetromino_pieces(bytes);
	if (num_of_tets > 26 || num_of_tets <= 0)
		return (-1);
	if (validate_tetrominos(buffer, bytes) == -1)
		return (-1);

	tetromino_data saved_coordinates[26];
	save_coordinates(file, saved_coordinates, num_of_tets);
	int map_size = find_map_size(num_of_tets);
	char **map = make_map(map_size);
	char **filled_map = fill_it(map, saved_coordinates, map_size, num_of_tets, 0);
	print_final_map(filled_map);
	return (0);
}

/* 
1. Divide bytes by 21; each tetromino should have 21 bytes (including newlines) between inputs
2. Return tetromino amount
*/

int	find_tetromino_pieces(int bytes)
{
	int num_of_tets = (bytes / 21) + 1;
	return (num_of_tets);
}

/* 
1. Simple equation to find smallest possible map size needed
*/

int	find_map_size(int num_of_tets)
{
	int i = 0;
	int count = 0;
	num_of_tets = (num_of_tets * 4);

	while (count < 26)
	{
		if (i * i >= num_of_tets)
			return (i);
		else
		{
			i++;
			count++;
		}
	}
	return(0);
}

/*
1. Using map_size, malloc space for double pointer map variable
(A double pointer allows us to create a 2-dimensional 
style array where each pointer value will point to its 
own defined array)
2. Malloc array for each pointer value
3. Set every array value to '.' because of syntax rules
*/

char **make_map(int map_size)
{
	int x = 0;
	int y = 0;
	int i = 0;
	char **map = (char**)malloc(sizeof(char*) * map_size);

	while (i < map_size)
	{	
		map[i] = (char*)malloc(map_size + 1);
		i++;
	}
	while (x < map_size)
	{
		while (y < map_size)
		{
			map[x][y] = '.';
			y++;    
		}
	x++;
	y = 0;
	}
	return (map);
}

/*
1. Print Final Map
*/

void	print_final_map(char **map)
{
	int i = 0;
	int j = 0;
	int size = ft_strlen(map[0]);

	while (i < size)
	{
		while (j < size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		j = 0;
		i++;
		ft_putchar('\n');
	}
}