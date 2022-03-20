/*                                                        :::      ::::::::   */
/*                                         			   :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: rosgill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:43:57 by rosgill           #+#    #+#             */
/*   Updated: 2021/11/10 15:59:51 by rosgill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i = 0;
	char	*result = (char*)malloc(sizeof(*result) * size + 1);

	while (i <= size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}