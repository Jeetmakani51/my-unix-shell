#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strtok(string,delimiters) splitting by " "
#include <unistd.h>
#include "history.h"
#include <sys/wait.h>

int main(){
    History h;
    h.head = NULL;
    h.tail = NULL;
    h.current = NULL;

    char input[1024];
    char *args[64];

    while(1){
        printf(">> "); // take prompt
        fgets(input, sizeof(input), stdin); // reads line from user including newline \n at the end
        input[strcspn(input,"\n")] = '\0'; // strip the newline
        char *token = strtok(input, " ");
        int i = 0;
        while(token != NULL){
            args[i] = token;
            i++;
            token = strtok(NULL, " "); // get next token
        }
        add(&h,input);
        args[i] = NULL;
        if(strcmp(args[0], "exit") == 0){
            break; // exit the while loop
        }
        if(strcmp(args[0],"history") == 0){
            print_all(&h);
            continue;
            
        }
        if(strcmp(args[0],"cd") == 0){ // cd cannot be implemented in child process
            if(args[1] == NULL){
                printf("cd : missing arguments\n");
            }else{
                if(chdir(args[1]) != 0){
                    perror("cd failed");
                }
            }
        }else{
            pid_t pid = fork();
            if(pid == 0){
                //child process - run the command
                execvp(args[0],args);
                // if execvp returns, it failed
                perror("execvp failed");
                exit(1);
            }else if(pid > 0){
                // parent process - wait for child process to finish
                waitpid(pid, NULL, 0);
            }else{
                // fork failed
                perror("fork failed"); // shell forked child, child became ls, printed the directory contents
            }
        }
    }
    cleanup(&h);
}