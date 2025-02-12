/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggargani<ggargani@student.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 07:47:57 by ggargani          #+#    #+#             */
/*   Updated: 2024/11/05 09:33:01 by ggargani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static size_t	count_words(const char *s, char c);
static size_t	word_len(const char *s, char c);
static char		*word_create(const char *s, size_t len);
static void		ft_free(char **s, int count);

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	wc;
	size_t	i;

	if (!s)
		return (NULL);
	wc = count_words(s, c);
	result = malloc((wc + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		result[i] = word_create(s, word_len(s, c));
		if (!result[i])
			return (ft_free(result, i), NULL);
		s += word_len(s, c);
		i++;
	}
	result[wc] = NULL;
	return (result);
}

static void	ft_free(char **s, int count)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free (s);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	*word_create(const char *s, size_t len)
{
	char	*word;
	size_t	i;

	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}
