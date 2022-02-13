#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    int i; int sum = 3;
    for (i = 0; i < 3; i++){
        pid = fork();
        if (pid == 0) {
            printf("my copy of i is %d\n",i);
            exit(0);
            printf("should not be excecuted\n");
        }
    }
    while (wait(NULL) != -1);   //empty loop
    printf("bye from main %d \n",sum);
    return 0;
}
