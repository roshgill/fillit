/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                               :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 12:02:25 by rosgill           #+#    #+#             */
/*   Updated: 2022/03/05 12:04:16 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Main Function
1. Take in file
2. Check if only one file is inputted else end function
3. Begin parse function
*/

#include "fillit.h"
int     main(int argc, char **argv)
{
    if (argc != 2)
    {    
        ft_putstr("Input 1 text file");
        return(0);
    }
    else if (parse(argv[1]) == -1)
        ft_putstr("Invalid Input");
    return (0);
}