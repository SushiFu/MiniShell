#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "tools.h"

int is_PATH(char* var)
{
    if (my_strlen(var) < 5)
        return 0;
    return (var[0] == 'P' && var[1] == 'A' &&
            var[2] == 'T' && var[3] == 'H' && var[4] == '=');
}

char** clean_paths(char* var)
{
    char* format;
    char** paths;
    int i;

    format = xmalloc(sizeof(char) * (my_strlen(var) - 4));
    for (i = 5; i < my_strlen(var); ++i)
        format[i - 5] = var[i];
    format[i - 5] = '\0';
    paths = str_to_words(format, ':');
    free(format);
    return (paths);
}

char** extract_paths(char** env)
{
    int i;
    char** paths;

    i = 0;
    paths = NULL;
    while(env[i] != NULL)
        if (is_PATH(env[i]))
        {
            paths = clean_paths(env[i]);
            break;
        }
    return (paths);
}
