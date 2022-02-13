#include <stdio.h>
#include <unistd.h>        
#include <sys/wait.h>
#include <stdlib.h> 
int main(){
    pid_t pid;
    char userChoice = 'z';
    while(userChoice != 'q'){
        wait(NULL);
        printf("a: ls \nb: ps \nc: who \nq for quit\n");
        scanf(" %c", &userChoice);    
        if((pid = fork()) == 0){
            if(userChoice == 'a') execlp("ls", "ls", NULL);
            if(userChoice == 'b') execlp("ps", "ps", NULL);
            if(userChoice == 'c') { execlp("who", "who", NULL); exit(0); }
        }          
    } 
    printf("parent terminated\n");
    return 0;
}

