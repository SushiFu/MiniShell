#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

#include "shell.h"
#include "tools.h"

int main(int argc, char **argv, char **env)
{
    (void)argc;
    (void)argv;

    if (env == NULL)
    {
        puterr("Argument env : failed");
        exit(1);
    }
    else
        shell(env);
    return (0);
}
