#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void f2(){
    int pid = getpid();
    printf(" fils numero 2 et son pid %d \n",pid );
    exit(0);
}

void f1 (int *a){
        int pid = getpid();
        *a= 10;
        printf("fils numero 1 et son id: %d\n",  pid);
        exit(0);
}

void pere(int *a){
        int pid = getpid();
        printf("le pere: %d et son id: %d\n", *a, pid);
        wait(0);
        wait(0);

}

int main(){
    int a=15;

    int id = fork();
    
    if(id == 0){
        f1(&a);
        
    }
    int id2 = fork();

    if (id2 == 0){
        f2();
    }

    pere(&a);

