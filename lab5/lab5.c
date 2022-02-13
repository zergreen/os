#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
/*10*/  pid_t cpid;
/*20*/  pid_t gcpid;
        /* fork another process */
/*30*/  cpid = fork();
        /* if (cpid < 0) { // error occured
        * fprintf(stderr, "Fork Failed");  exit(0);
        * } else { */
/*40*/  if (cpid == 0) { /* child process */
/*50*/      gcpid = fork();
/*60*/      if (gcpid == 0) { //grandchild
/*70*/          printf("Can you see this3?\n");
/*80*/          exit(0);
/*90*/      }
/*100*/     //execlp("/bin/ls", "ls", NULL);  /* A */
//execlp("cd","cd",NULL);
execlp("cp","cp","lab5.c","sa.c",NULL);
/*110*/     printf("can you see this2? it's error\n"); /* B */
exit(0);
/*120*/ }
            wait (NULL);    printf("received Child Complete\n");
/*160*/     exit(0);

    /* } if error */
/*140*/     printf("can you see this1?\n"); /* C */
/*150*/         return 0;
} //main
