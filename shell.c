#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "shell.h"
#include "prompt.h"
#include "path.h"
#include "builtins.h"
#include "tools.h"

void check_exit(char* cmd, char**args, char** paths)
{
    if (str_equals(cmd, "exit"))
    {
        free_tabs(args, paths);
        exit(0);
    }
}

int check_builtins(char* cmd, char** args)
{
    return cd(cmd, args);
}

void exec_cmd(char* cmd, char** args, char** paths, char** env)
{
    int	i;
    pid_t	pid;
    char* tmp;

    i = 0;
    pid = fork();
    if (pid == 0)
    {
        while (paths[i] != NULL)
        {
            tmp = str_tri_concat(paths[i], "/", cmd);
            execve(tmp, args, env);
            free(tmp);
            ++i;
        }
    }
    else
    {
        i = 1;
        wait(&i);
    }
}

void free_tabs(char** args, char** paths)
{
    int i;

    i = 0;
    while(args[i] != NULL)
    {
        free(args[i]);
        ++i;
    }
    i = 0;
    while(paths[i] != NULL)
    {
        free(paths[i]);
        ++i;
    }
    free(args);
    free(paths);
}

void shell(char** env)
{
    char buffer[BUFF_SIZE];
    char *cmd;
    char **args;
    char **paths;

    while (1)
    {
        prompt();
        if (read(1, buffer, BUFF_SIZE) < 0)
            exit(1);
        else
        {
            args = str_to_words(buffer, ' ');
            paths = extract_paths(env);
            cmd = args[0];

            check_exit(cmd, args, paths);
            if (!check_builtins(cmd, args))
                exec_cmd(cmd, args, paths, env);

            free_tabs(args, paths);
        }
    }
}
