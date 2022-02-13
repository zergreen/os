#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    char userChoice = 'z' ;
    while (userChoice != 'q') {        
        pid = fork();   
        wait(NULL);
        printf("a: ls \n");
        printf("b: ps \n");
        printf("c: who \n");
        printf("q for quit \n");
        scanf(" %c", &userChoice);

        if (pid<0) {
            fprintf(stderr , "Fork failed\n");
            exit(-1);
        } else if(pid==0) {
            if (userChoice == 'a') {
                execlp("ls", "ls", "-la", NULL);
            }
            if (userChoice == 'b') {
                execlp("ps", "ps", "-l", NULL);
            }
            if (userChoice == 'c') {
                execlp("who", "who", NULL);
            }
        }
    } //while
    printf("parent terminated\n");
}
