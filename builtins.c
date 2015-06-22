#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "tools.h"

int cd(char* cmd, char** args)
{
    if (!str_equals(cmd, "cd"))
        return 0;

    if (chdir(args[1]) == -1)
        puterr("Could not change directory : target does not exist\n");

    return 1;
}
