#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char** envp)
{
    char** env;
    char* shell_path;

    for (env = envp; *env != 0; env++)
    {
        printf("%s\n", *env);
    }
    shell_path = getenv("SHELL_PATH");
    if(shell_path!=NULL){
        printf("SHELL_PATH value is %s\n",shell_path);
    }else{
        printf("SHELL_PATH value is unknown\n");
    }
    return(0);
}
