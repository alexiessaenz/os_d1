#include <pthread.h>
#include <stdio.h>
#include <string.h>

struct person
{
    char name[50];
    char dui[10];
    int age ;
};


void * son1(void *args){
    struct person *personArgs;
    personArgs = (struct person *) args;
    printf("Nombre: %s\nDui: %s\nEdad: %d\n", personArgs->name, personArgs->dui, personArgs->age);
}
void * hilo(void *args){
    pthread_t son;
    pthread_create(&son, NULL, son1, args);
    pthread_join(son, NULL);
}


int main(int argc, char const *argv[])
{
    pthread_t h1;
    struct person person1;
    // Función de la libreria string que copia un dato a una variable
    strcpy(person1.name, "moises");
    strcpy(person1.dui, "04347658-5");
    person1.age=21;

    pthread_create(&h1, NULL, hilo, (void *)&person1);
    pthread_join(h1, NULL);
    return 0;
}
