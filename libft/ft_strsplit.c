/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:24:32 by tlaberro          #+#    #+#             */
/*   Updated: 2017/11/23 10:05:53 by tlaberro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordcount(const char *str, char c)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (!(str))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
			len++;
		}
		i++;
	}
	if (str[i - 1] != c)
		return (len + 1);
	else
		return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	len;
	int		i;
	int		x;

	i = 0;
	len = ft_wordcount(s, c);
	if (!(dst = (char **)malloc(sizeof(*dst) * len + 1)) || !(s))
		return (NULL);
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		x = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		dst[len] = ft_strsub(s, x, (i - x));
		len++;
		while (s[i] == c)
			i++;
	}
	dst[len] = NULL;
	return (dst);
}
