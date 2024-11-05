/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Gsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: modryouc <modryouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:02:58 by modryouc          #+#    #+#             */
/*   Updated: 2024/11/05 17:12:04 by modryouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_space(char c) {
    return (c <= 32);
}

int count_words(char *str) {
    int i = 0;
    int count = 0;
    int word = 1;

    while (str[i]) {
        if (!is_space(str[i]) && word == 1) {
            count++;
            word = 0;
        } else if (is_space(str[i]) && word == 0) {
            word = 1;
        }
        i++;
    }
    return count;
}

char *allocate_word(const char *str, int start, int end) 
{
    int length;
	int i;

	length = end - start;
    char *word = (char *)malloc((length + 1) * sizeof(char));
    if (word == NULL)
        return NULL;
	i = 0;
    while (i < length)
	{
        word[i] = str[start + i];
		i++;
    }
    word[length] = '\0';
    return word;
}

char **ft_split(char *str) 
{
    int word_count = count_words(str);
    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (result == NULL) 
	{
        return NULL;
    }

    int i = 0;
    int word_index = 0;
    int j = 0;
    while (str[i]) 
	{
        if (!is_space(str[i])) 
		{
            int start = i;
            while (str[i] && !is_space(str[i])) 
			{
                i++;
            }
            int end = i;
            result[word_index] = allocate_word(str, start, end);
            if (result[word_index] == NULL) {
                // Free any previously allocated words in case of failure
                while (j < word_index)
                {
                    free(result[j]);
                    j++;
                }
                free(result);
                return NULL;
            }
            word_index++;
        }
        else
            i++;
    }
    result[word_index] = NULL; // Null-terminate the result array
    return result;
}

int main() {
    char str[] = "  Hello   world   this is   a test  ";
    char **words = ft_split(str);

    // Print the words to test
    for (int i = 0; words[i] != NULL; i++) {
        printf("Word %d: %s\n", i, words[i]);
        free(words[i]); // Free each word after printing
    }
    free(words); // Free the result array

    return 0;
}
