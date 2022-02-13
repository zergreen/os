#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    int i;
    pid = fork();
    if (pid > 0)    /* parent */
    {
        i = 1;
        printf("I am parent my pid = %d, i = %d\n", getpid(), i);
    }
    else    /* child */
    {
        i = 2;
        sleep(5);
        printf("I am child my pid = %d, i = %d\n", getpid(), i);
    }
    return 0;
}
