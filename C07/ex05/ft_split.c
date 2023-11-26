#include <stdlib.h>

int	is_charset(char *str, char *chr_set)
{
	int		length;

	if (!*chr_set)
		return (-1);
	length = 0;
	while (str[length] && chr_set[length] == str[length])
		length++;
	if (!chr_set[length])
		return (length);
	return (-1);
}

int	word_len(char *str, char *chr_set)
{
	int		length;

	length = 0;
	while (str[length] && is_charset(str + length, chr_set) == -1)
		length++;
	return (length);
}

int	get_word_count(char *str, char *chr_set)
{
	int		count;
	int		word_incoming;
	int		chrset_len;

	word_incoming = 1;
	count = 0;
	while (*str)
	{
		chrset_len = is_charset(str, chr_set);
		if (word_incoming && chrset_len == -1)
		{
			if (word_len(str, chr_set) > 0)
				count++;
			word_incoming = 0;
		}
		else if (chrset_len > 0)
		{
			str += chrset_len - 1;
			word_incoming = 1;
		}
		str++;
	}
	return (count);
}

int	get_word(char *str, char *chr_set, int word_index)
{
	int		count;
	int		word_incoming;
	int		index;

	word_incoming = 1;
	count = 0;
	index = 0;
	while (str[index])
	{
		if (word_incoming && is_charset(str + index, chr_set) == -1)
		{
			if (count == word_index)
				return (index);
			count++;
			word_incoming = 0;
		}
		else if (is_charset(str + index, chr_set) > 0)
		{
			index += is_charset(str + index, chr_set) - 1;
			word_incoming = 1;
		}
		index++;
	}
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		strs_size;
	int		index;
	int		word_index;
	int		i;

	strs_size = get_word_count(str, charset) + 1;
	strs = (char **) malloc(sizeof(char *) * (strs_size));
	strs[strs_size - 1] = 0;
	index = 0;
	while (index < strs_size - 1)
	{
		word_index = get_word(str, charset, index);
		strs[index] = (char *) malloc(sizeof(char) * \
		(word_len(str + word_index, charset) + 1));
		i = 0;
		while (i < word_len(str + word_index, charset))
		{
			strs[index][i] = str[word_index + i];
			i++;
		}
		strs[index++][i] = '\0';
	}
	strs[strs_size - 1] = 0;
	return (strs);
}
