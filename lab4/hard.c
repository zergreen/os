#include <stdio.h>
#include <sys/types.h>  //fork()
#include <unistd.h>     //fork()
#include <sys/wait.h>   //wait()
#include <stdlib.h>     //exit()

int main() {
    pid_t pid, pidsub;
    int i,j;
    printf("only parent before fork\n");
    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid == 0) { //child
            if ((i % 2) == 0) {
                printf("I am the child no %d\n", i);
                int num_gc = 3  ;   /* 8.1 */ //num_gc = number grandchild
                for (j = 0; j < num_gc; j++) {
                    pidsub = fork();                /* 8.2 */
                    if (pidsub == 0) { //grand child
                        printf("I am granchild num %d of even child no %d\n", j, i);
                        exit(0);            /* 8.3 */
                    }
                } //for j
                while(wait(NULL) != -1)                    /* 8.4 */
                exit(0);
            } /*even child */ else { //odd childed {
                printf("I am the child no %d\n", i);
                int num_gc = 4   ;   /* 8.5 */
                for (j = 0; j < num_gc; j++){
                    pidsub = fork();
                    if (pidsub == 0            /* 8.6 */ ){
                        printf("I am granchild num %d of odd child no %d\n", j, i);
                        exit(0);            /* 8.7 */
                    }
                }//for j
                while(wait(NULL) != -1);
                exit(0);
            }
            //exit(0);              /* 8.8 */
        }//if child
    }//i
    while (wait(NULL) != -1) ;
    return 0;
}

