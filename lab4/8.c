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
        if (pid == 0) {
            if ((i % 2) == 0) {
                printf("I am the child no %d\n", i);
                int num_gc =    ;   /* 8.1 */
                for (j = 0; j < num_gc; j++) {
                                    /* 8.2 */
                    if (pidsub == 0) {
                        printf("I am granchild num %d of even child no %d\n", j, i);
                                    /* 8.3 */
                    }
                } //for j
                                    /* 8.4 */
                exit(0);
            } /*even child */ else { //odd childed {
                printf("I am the child no %d\n", i);
                int num_gc =    ;   /* 8.5 */
                for (j = 0; j < num_gc; j++){
                    pidsub = fork();
                    if (            /* 8.6 */ ){
                        printf("I am granchild num %d of even child no %d\n", j, i);
                                    /* 8.7 */
                    }
                }//for j
                while(wait(NULL) != -1);
                exit(0);
            }
            //exit(0);              /* 8.8 */
        }//if child
    }//i
}
