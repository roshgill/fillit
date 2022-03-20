/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                            :+:     :+:   :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:37:44 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 13:51:53 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Validate_Tetrominos
1. Validate all inputted tetrominos (check for specific syntax)
2. Validate if all inputted tetrominos are correct pieces (A piece is valid if it has 6 or 8 touches_check)
*/

int validate_tetrominos(char *buff, int bytes_amount)
{
	int i = 0;
	int return_value;
	int touches_value;

	while (i <= bytes_amount)
	{
		return_value = syntax_check(buff + i);
		if (return_value == 0 && (bytes_amount <= (i + 21)))
			return (0);
		if (return_value == -1)
			return (-1);

		touches_value = touches_check(buff + i);
		if (touches_value < 6 || touches_value > 9)
			return (-1);
		i += 21;
	}
	return(0);
}

/*
1. Calls the main checker function
2. Will return either -1 for error, 1 to continue checking, 0 if all are correct and validated 
*/

int syntax_check(char *buff)
{
	int return_value = hashtag_period_newline_check(buff, 0, 0, 0, 0);
	return (return_value);
}

/*
1. Check for the correct amount of hashtags, periods, newlines of a tetromino input
*/

int hashtag_period_newline_check(char *buff, int i, int hashtag_counter, int period_counter, int new_line_counter)
{
	while (i <= 19)
	{
		if (buff[i] == '#')
			hashtag_counter++;
		if (buff[i] == '.')
			period_counter++;
		if (buff[i] == '\n')
			new_line_counter++;
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n' && buff[i] != '\0')
			return (-1);
		if (buff[i] != '#' && buff[i] != '.' && buff[i] == '\0' && i == 19)
		{
			if (final_syntax_verification(hashtag_counter, period_counter, new_line_counter) == 0)
				return (0);
		}

		i++;
	}
	if (final_syntax_verification(hashtag_counter, period_counter, new_line_counter) == 1)
		return (1);
	return(-1);
}

/*
1. Check if the amount of hashtags, periods, and newlines are correct
2. Check if the tetromino is the last one or if there are more remaining
*/

int	final_syntax_verification(int hashtag_counter, int period_counter, int new_line_counter)
{
	if (hashtag_counter == 4)
	{
		if (period_counter == 12)
		{
			if (new_line_counter == 3)
				return (0);
			else if (new_line_counter == 4)
				return (1);
		}
	}
	return (-1);
}

/*
1. Call touches and return amount of touches
*/

int touches_check(char *buff)
{
	int i = 0;
	int touch = 0;

	while (i < 19)
	{
		touch = touches(buff, i, touch);
		i++;
	}
	return (touch);
}

/*
1. Will check the top, bottom, left, and right of the hashtag's position
2. If there is another hashtag at those positions we will increment touch
3. Return touch
*/

int touches(char *buff, int i, int touch)
{
	if (buff[i] == '#')
	{
		if (buff[i + 1] == '#')
			touch++;
		if (buff[i - 1] == '#')
			touch++;
		if (buff[i + 5] == '#')
			touch++;
		if (buff[i - 5] == '#')
			touch++; 
	}
	return(touch);
}