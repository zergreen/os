#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //header file for sleep()
#include <pthread.h>

int csum; /* this data is shared by the threads(s) */
void *runner(void *param); /* the thread */
int main(int argc, char *argv[]) /* !2.1 parametre via run file */
{
    int msum = 0;
    pthread_t tid; /* the thread identifier */
    pthread_attr_t attr; /* set of attributes for the thread */
    pthread_attr_init(&attr); 
    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]); /* !2.2 child thread */
    /* now wait for the thread to exit */
    pthread_join(tid,NULL);
    
    /* !2.3 parent thread */
    int param = atoi(argv[1]);
    if (param > 0)
    {
        for (int i = 1; i <= param; i++)
            msum += i;
    }
    
    printf("param = %d\n", param);
    printf("msum = %d\n", msum);
    printf("csum = %d\n", csum);
    printf("csum - msum = %d\n", csum-msum); /* !2.4 different for msum - csum */ 

    printf("ʕ•ᴥ•ʔ MISSION COMPLETE ʕ•ᴥ•ʔ\n");
    return 0;
}

/* child method */
void *runner(void *param)
{
    int upper = atoi(param);
    int i;
    csum = 0;
    if (upper > 0)
    {
        for (i = 1; i <= upper*2; i++)
            csum += i;
    }
    pthread_exit(0);
}
