#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tools.h"

int my_strlen(char *c)
{
    int   i;

    i = 0;
    while (c[i] != '\0' && c[i] != '\n')
        i++;
    return (i);
}

void putstr(char *c)
{
    write(1, c, my_strlen(c));
}

void puterr(char *c)
{
    write(2, c, my_strlen(c));
}

void* xmalloc(int size)
{
    void  *data;

    if ((data = malloc(size)) == NULL)
    {
        puterr("Could not Malloc");
        exit(1);
    }
    return (data);
}

int count_words(char* str, char delim)
{
    int count;

    count = 1;
    for (int i = 0; i < my_strlen(str); ++i)
        if (str[i] != delim && str[i + 1] == delim)
            ++count;
    if (str[my_strlen(str) - 1] == delim)
        --count;
    return (count);
}

int word_length(char* word, int pos, char delim)
{
    int i;

    i = pos;
    while(word[i] != delim && word[i] != '\0' && word[i] != '\n')
        ++i;
    return i;
}

char** str_to_words(char* str, char delim)
{
    int count;
    int letter;
    int i;
    char** tab;

    count = 0;
    letter = 0;
    tab = xmalloc(sizeof(char*) * (count_words(str, delim) + 1));
    for (i = 0; i < count_words(str, delim); ++i)
    {
        if (str[count] == '\0' || str[count] == '\n')
            break;
        while(str[count] == delim)
            ++count;
        letter = 0;
        tab[i] = xmalloc(sizeof(char) * (word_length(str, count, delim) + 1));
        while(str[count] != delim && str[count] != '\0' && str[count] != '\n')
        {
            tab[i][letter] = str[count];
            ++letter;
            ++count;
        }
        tab[i][letter] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}

int str_equals(char* str1, char* str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (int i = 0; i < my_strlen(str1); ++i)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}

char* str_concat(char* str1, char* str2)
{
    int cpt;
    char* res;

    cpt = 0;
    res = xmalloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    for (int i = 0; i < my_strlen(str1); ++i)
    {
        res[cpt] = str1[i];
        ++cpt;
    }
    for (int i = 0; i < my_strlen(str2); ++i)
    {
        res[cpt] = str2[i];
        ++cpt;
    }
    res[cpt] = '\0';
    return res;
}

char* str_tri_concat(char* str1, char* str2, char* str3)
{
    char* tmp;
    char* res;

    tmp = str_concat(str1, str2);
    res = str_concat(tmp, str3);
    free(tmp);
    return res;
}
