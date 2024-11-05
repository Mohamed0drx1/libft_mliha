/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modryouc <modryouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:21:25 by modryouc          #+#    #+#             */
/*   Updated: 2024/11/04 18:04:06 by modryouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	calcu(int n)
{
	int count;
	
	count = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count += 1;
	return (count);
}

char	*ft_itoa(int n)
{
	char *str;
	int j;
	int i;
	
	i = 0;
	j = calcu(n);
	str = (char *)malloc((j + 2) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i++;
		j++;
	}
	str[j + 1] = '\0';
	j--;
	while (j >= i)
	{
		str[j] = (n % 10) + 48;
		n = (n / 10);
		j--;
	}
	return (str);
}
int main()
{
	char *s;
	int n = 1337;
	s = ft_itoa(n);
	if (!s)
		printf ("NULL"); 
	printf ("%s", s);
}