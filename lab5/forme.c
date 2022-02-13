#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

    pid_t pid;

    printf("Before fork\n");

    pid = fork();

    if(pid>0) {
        // wait(NULL);
        printf("I am parent\n");
        printf("My parent id = %d\n", getpid());
        printf("My child id is = %d\n", getppid());

        exit(1);
    }
    else if(pid==0){
        printf("I am child\n");
        printf("My parent id = %d\n", getpid());
        printf("My child id is = %d\n", getppid());
        exit(0);
    }

    else {
        printf("fork failed\n");
    }

    printf("what happen\n");
    // wait(NULL);
    while(wait(NULL) != -1);
    printf("After fork\n");
    // printf("boring\n");

    return 0;
}
