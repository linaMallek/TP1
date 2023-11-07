
/* int main()
{
FILE *ffile ;    
ffile = fopen("file.txt","r");

printf("Bonjour\n");

int id = fork(); 
if(id == 0){
        f1(&a);
        
    }
    int id2 = fork();

    if (id2 == 0){
        f2();
    }
} 
 if(c>47&&c<58){
                if (((c-48) % 2)!= 0)
                {printf(" Integer du fils 1: %d \n",c-48);}  
    }*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
	
void f1 (FILE *file,FILE *F1){
     
       
        int c; 
        int pid = getpid();

        file = fopen("file.txt","r");
        F1 = fopen("file1.txt","w");
        while((c=fgetc(file))!=EOF){
            if(c>47&&c<58){
                if (((c-48) % 2)!= 0)
                { // mettre les elemnts impair dans F1 
                 
                 fputc(c, F1);
                }  
    }
        }
        fclose (file);
        fclose (F1);
         printf("je suis le fils 1 jai finis mon execuion id : %d \n", pid);
        exit(0);
}

void f2(FILE *file,FILE *F2){
        char c; 
        int pid = getpid();

        file = fopen("file.txt","r");
        F2 = fopen("file2.txt","w");
        printf("je suis le fils 2 \n ");
        while((c=fgetc(file))!=EOF){
          
             if(c>47&&c<58){
                if (((c-48)%2)==0)
                {
                    fputc(c, F2);
                }  
             }
        }
        fclose (file);
        fclose (F2);
         printf("je suis le fils 2 jai finis mon execuion id : %d \n", pid);
        exit(0);
}

// afficher le fichier F2 des impairs 

void f3 (FILE *file){
    char c; 
    int pid = getpid();
   
    file = fopen("file1.txt","r");
       while((c=fgetc(file))!=EOF){
               
              printf(" Integer du fils 1: %d \n",c-48);  
 
       }
       fclose (file);
        printf("je suis le fils 3 jai finis mon execuion id : %d \n", pid);
       exit(0);
}

// afficher le fichier F2 des pairs 

void f4 (FILE *file){
    char c; 
    int pid = getpid();
 
    file = fopen("file2.txt","r");
       while((c=fgetc(file))!=EOF){
               
              printf(" Integer du fils 2: %d \n",c-48);  
 
       }
       printf("je suis le fils 4 jai finis mon execuion id : %d \n", pid);
       fclose (file);
       exit(0);
}


void pere(int a){
        int pid = getpid();
        printf("le pere: %d et son id: %d\n", a, pid);
        

}

void main(){
  
    FILE *ffile ;  
    FILE* F1 = NULL;
    FILE* F2 = NULL; 
    int n,num;  

     //printf("Donnez un nombre aleatoire \n");
    // scanf("%d",n);
    // ouvrir fichier en ecriture 
     //ffile = fopen("file.txt","w");
     /* for (int i = 0; i<n; i++)
      {      
            num = rand() + 1;
            fprintf(ffile, "%d\n", num);

      } */
   // fclose(ffile);

    ffile = fopen("file.txt","r");

    // creer premier fils 
    int id = fork();
    
    if(id == 0){
        f1(ffile,F1);
        
    }
    // creer deuxieme fils 
  int id2 = fork();
  
   if (id2 == 0){
        f2(ffile,F2);
    }
    
    // creer troisieme fils
  int id3 = fork();
  
   if (id3 == 0){
        f3(F1);
    }

    // creer quatrieme fils
  int id4 = fork();
  
   if (id4 == 0){
        f4(F2);
    }
    pere(1);
  
  fclose (ffile);

}
