/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonchoi <jonchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:45:13 by jonchoi           #+#    #+#             */
/*   Updated: 2023/01/15 23:35:52 by jonchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	is_digit(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		if (!(str[j] >= '0' && str[j] <= '9'))
		{
			if (str[j] != '\n')
				print_error("contents error\n");
		}
		j++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str [i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str [i] == '-' || str [i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	is_digit(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
