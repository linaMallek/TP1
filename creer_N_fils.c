#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <nl_types.h>
#include <string.h>


void fils(int numero_fils){

void ffils(int i , int j)
{
  int pid = getpid();
  int ppid = getppid();
  printf("fils numero %d du pere %d mon id %d et son id du pere : %d \n", i,j, pid,ppid);  
  exit(0);
}

 for(int i=0;i<= numero_fils-1; i++){
            int ids = fork();
            if( ids==0)
             {ffils(i+1 , numero_fils);}
        } 
        
       
        
        for(int i=0; i<numero_fils-1; i++){
            wait(0);
        }
        printf("fils %d \n",numero_fils);
        
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

    printf("donnez la valeur de n \n");
    scanf(" %d: ", &nombre_fils);

    for(int i=0; i<nombre_fils;i++){
        ids = fork();
        if(ids==0){
            fils(i+1);
        }
    }

    
    return 0;
}