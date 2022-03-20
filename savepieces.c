/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savepieces.c                                      :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:37:44 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 13:51:53 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Save Coordinates
1. Save per 21 bytes into **char variable buffer
2. Get the coordintates of each hashtag and save into the 2-dimensional array struct
3. Move the coordinates of each piece to the top left
*/

int	save_coordinates(char *file, tetromino_data *saved_coordinates, int num_of_tets)
{
	int letter = 'A';
	int struct_counter = 0;
	FILE *file_descriptor = fopen(file, "r");
	char **buffer;

	while (struct_counter < num_of_tets)
	{
		buffer = (read_file_save_to_char(file_descriptor));
		get_coordinates(buffer, saved_coordinates, struct_counter);
		move_coordinates_top_left(saved_coordinates, struct_counter);
		free(buffer);
		saved_coordinates[struct_counter].letter = letter;
		letter++;
		struct_counter++;
	}
	fclose(file_descriptor);
	return (0);
}

/*
1. Malloc enough space for char **buffer
2. Use fgets function to read and save per line
3. Read only 4 lines and return buffer
*/

char **read_file_save_to_char(FILE *file_descriptor)
{
	int i = 0;
	char **buffer = (char**)malloc(sizeof(char*) * 20);
	char line[80] = {0};

	while (i < 4)
	{
		fgets(line, 80, file_descriptor);
		buffer[i] = ft_strdup(line);
		i++;
	}
	fgets(line, 80, file_descriptor);
	return (buffer);
}

/*
1. Function will find the coordinates position and save them into the struct
*/

tetromino_data get_coordinates(char **buffer, tetromino_data *saved_coordinates, int struct_counter)
{
	int x = 0;
	int y = 0;
	int counter = 0;

	while (counter < 4)
	{
		while (x < 4)
		{
			while (y < 4)
			{
				if (buffer[x][y] == '#')
				{
					saved_coordinates[struct_counter].x[counter] = x;
					saved_coordinates[struct_counter].y[counter] = y;
					counter++;
				}
				y++;
			}
		y = 0;
		x++;	
		}
	}
	return (*saved_coordinates);
}

/*
1. Function will save every tetromino position to the top left in the structs
2. Initialize the 0th x,y coordinates into temporary variables
3. Subtract every x,y coordinate positions with the starting postion coordinates
*/

int move_coordinates_top_left(tetromino_data *saved_coordinates, int struct_counter)
{
	int counter = 0;
	int temp_x = saved_coordinates[struct_counter].x[counter];
	int temp_y = saved_coordinates[struct_counter].y[counter];
	int x1 = temp_x;
	int y1 = temp_y;
\
	while (counter < 4)
	{
		if (counter == 0)
		{
			saved_coordinates[struct_counter].x[counter] = temp_x - x1;
			saved_coordinates[struct_counter].y[counter] = temp_y - y1;
			counter++;
		}
		if (!(move_to_top_left(saved_coordinates, struct_counter, counter, x1, y1) == 1))
			return (-1);
		counter++;
	}
	return (0);
}

//Part of move_coordinates_top_left
int move_to_top_left(tetromino_data *saved_coordinates, int struct_counter, int counter, int x1, int y1)
{
	int temp_x;
	int temp_y;

	temp_x = saved_coordinates[struct_counter].x[counter];
	temp_y = saved_coordinates[struct_counter].y[counter];
	if (counter < 4)
	{
		saved_coordinates[struct_counter].x[counter] = temp_x - x1;
		saved_coordinates[struct_counter].y[counter] = temp_y - y1;
		return (1);
	}
	return (-1);
}