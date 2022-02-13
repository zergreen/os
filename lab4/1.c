#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(/* int argv, char** argc */){
    pid_t pid;
    int i = 0;  //prevent garbage

    pid = fork();
    if (pid > 0) { //parent
        i = 1;
        printf("my copy of i is %d\n",i);
    } else {    //child
        i = 2;
        printf("my copy of i is %d\n",i);
    }

    return 0;
}
