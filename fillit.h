/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:02:25 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 12:04:16 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Header File
A header file is a file with extension .h which contains C function declarations 
and macro definitions to be shared between several source files. There are two types 
of header files: The files that the programmer writes and the files that comes with your compiler.
*/

#ifndef FILLIT_H
#define FILLIT_H
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

#define BUFF_SIZE 4

typedef	struct	s_array
{
	char	letter;
	int		x[4];
	int		y[4];
}	tetromino_data;

int main(int argc, char **argv);
int parse(char *file);
int validate_tetrominos(char *buff, int bytes_amount);
int	syntax_check(char *buff);
int hashtag_period_newline_check(char *buff, int i, int hashtag_counter, int period_counter, int new_line_counter);
int	final_syntax_verification(int hashtag_counter, int period_counter, int new_line_counter);
int	touches_check(char *buff);
int touches(char *buff, int i, int touch);
int	find_tetromino_pieces(int bytes);
int	find_map_size(int num_of_tets);
int	save_coordinates(char *file, tetromino_data *saved_coordinates, int num_of_tets);
char **read_file_save_to_char(FILE *file_descriptor);
int	get_next_line(const int file_descriptor, char **line);
int	b_check(int bytes, char *str[4864], const int file_descriptor, char **line);
int	find_newline_savetoline(char **stack, char **line);
tetromino_data get_coordinates(char **buffer, tetromino_data *saved_coordinates, int struct_counter);
int move_coordinates_top_left(tetromino_data *saved_coordinates, int struct_counter);
int move_to_top_left(tetromino_data *saved_coordinates, int struct_counter, int counter, int x1, int y1);
char **make_map(int map_size);
char  **fill_it(char **map, tetromino_data saved_coordinates[26], int map_size, int num_of_tets, int struct_counter);
int fill_map(char **map, tetromino_data saved_coordinates[26], int map_size, int num_of_tets, int struct_counter);
int find_open_space(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int map_size, int open_space_count, int struct_counter);
char **place_pieces(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int open_space_count, int struct_counter);
char **remove_pieces(char **map, tetromino_data saved_coordinates[26], int temp_x, int temp_y, int open_space_count, int struct_counter);
void	print_final_map(char **map);

#endif