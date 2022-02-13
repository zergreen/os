#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid[3], w;
    int num, sum = 0, i, status;
    printf("Enter a positive number ");
    num = getchar() - 48 ;   //scanf(%d,&num);
    //ignore if (num <= 0)
    for (i = 0; i < 3; i++){
        if ((pid[i] = fork()) == 0) {
            printf("I am child no %d. my copy of num %d\n", i, num);
            exit(i);
        }
    }
    for (i = 0; (w = waitpid( pid[i], &status, 0 )) && w != -1; ++i) {
        printf("Wait on PID: %d returns value of : %d\n", w, WEXITSTATUS(status));
    }
}
