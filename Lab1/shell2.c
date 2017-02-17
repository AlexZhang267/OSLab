#include <stdio.h>
#include <string.h>
#include <zconf.h>
#include <sys/wait.h>

void  parse(char *line, char **argv)
{
    while (*line != '\0') {   
        while (*line == ' ' || *line == '\t' || *line == '\n')
            *line++ = '\0';   
        *argv++ = line;       
        while (*line != '\0' && *line != ' ' &&
               *line != '\t' && *line != '\n')
            line++;           
    }
    *argv = '\0';             
}

int main(){
    int max_length = 1024;
    char command[max_length];
    char *argv[64];
    char* exit = "exit";
    int child_id = 0;
    int status = 0;

    do{
        printf("> ");
        fgets(command,max_length,stdin);

        command[strlen(command)-1] = '\0';

        child_id = fork();
        if (child_id!=0){
            printf("Loading new process with id %d\n",child_id);
            wait(&status);

        }else{
        	printf("> Parent pid: %d\n", getppid());
            parse(command,argv);
            execvp(*argv, (char**)argv);
            printf("Shell error: No such file or directory\n");
        }


    }while (strcmp(command,exit)!=0);
    return 0;
}
