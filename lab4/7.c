#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int i = 0, num, sum = 0;
    printf("Enter a positive number : ");
    scanf("%d", &num);  //num = getchar() - 48; while(getchar() != '\n')
    if(num <= 0) {
        printf("You did not enter a positive number \n");
        exit(1); //exit(-1);
    }
    if (pid = fork() > 0) {
        for (i = 1; i <= num; i++) 
            sum += i;
        } else {
            for (i = 1; i <= 2 * num; i++)
                sum += i;
            printf("I am child my sum = %d\n", sum);
        }
    wait(NULL);
    printf("I am parent my sum = %d\n", sum);

    return 0;
}
