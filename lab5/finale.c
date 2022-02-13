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
        //printf("PID = %d , PPID = %d \n",getpid(),getppid());
        printf("a: ls \n");
        printf("b: ps \n");
        printf("c: who \n");
        printf("q for quit \n");
        //printf("Enter : ");
        scanf(" %c", &userChoice);

        if (pid<0) {
            fprintf(stderr , "Fork failed\n");
            exit(-1);
        } else if(pid==0) {
            if (userChoice == 'a') {
                execlp("ls", "ls", "-la", NULL);
                //printf("ls : exec failed\n");
                //exit(0);
            }
            if (userChoice == 'b') {
                execlp("ps", "ps", "-l", NULL);
                //printf("ps : exec failed\n");
                //exit(0);
            }
            if (userChoice == 'c') {
                execlp("who", "who", NULL);
                //printf("who : exec failed\n");
                //exit(0);
            }
        }
    } //while
    printf("parent terminated\n");
}

