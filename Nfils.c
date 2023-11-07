#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>



void fn(int numero_fils){
        int pid = getpid();
        printf("fils numero %d et son id: %d\n", numero_fils,  pid);
        exit(0);
}

void pere(int nombre_fils){
        int pid = getpid();
        printf("le pere et son id: %d\n", pid);

        for(int i; i<nombre_fils; i++){
            wait(0);
        }
}

int main(){
    int nombre_fils;
    int ids;

    printf("donner la valeur de n \n");
    scanf(" %d: ", &nombre_fils);

    for(int i=0; i<nombre_fils;i++){
        ids = fork();
        if(ids==0){
            fn(i+1);
        }
    }

    pere(nombre_fils);
    return 0;
}