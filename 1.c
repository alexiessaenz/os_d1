#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void * msg(void *arg){
    char nombre[45], apellido[45];
    int i;
    
    printf("Introduce un nombre:\n");
    scanf("%s",nombre);

    printf("Introduce un apellido:\n");
    scanf("%s",apellido);

    strcat(nombre,apellido);
    if (strlen(nombre)>25)
    {
        printf("WILL TRUNCATE\n\n");
    } 
    else
    {
        printf("NO PROBLEM\n\n");
        printf("pid: %d\n", getpid());

    }
    
        return NULL;
}

int main(int argc, char *argv []) {
    pthread_t h;
    
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&h, NULL, msg, NULL);
        pthread_join(h,NULL);
    }
    
    
    printf("\tfin\n");
    
   return 0;
}