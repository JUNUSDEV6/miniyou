/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdendonc <rdendonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 11:26:51 by rdendonc          #+#    #+#             */
/*   Updated: 2024/09/25 11:26:52 by rdendonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57))
		|| ((c >= 65) && (c <= 90))
		|| ((c >= 97) && (c <= 122)))
		return (1);
	else
		return (0);
}

/*int	main()
	{
		int	a;

		a = 'K';
		printf("%d", (ft_isalnum(a)));
		printf("%d", (isalnum(a)));

		return(0);
	}*/
