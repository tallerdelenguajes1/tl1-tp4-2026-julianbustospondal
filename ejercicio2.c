#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Tarea
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;
typedef struct Tnodo
{
    Tarea T;
    struct Tnodo *siguiente;
} Tnodo;

Tnodo *CrearListaVacia();
Tnodo *CrearNodo(Tarea dato);
void InsertarNodo(Tnodo **Start, Tnodo *Nodo);

int main()
{
    int continuar = 1;
    int duracion;
    int id = 1000;
    Tnodo *Start = CrearListaVacia();
    char descriptemp[100];
    while (continuar == 1)
    {
        Tarea nuevaTarea;
        nuevaTarea.TareaID = id;
        id++;

        printf("describir tarea\n");
        scanf("%s", descriptemp);
        nuevaTarea.Descripcion = (char *)malloc((strlen(descriptemp) + 1) * sizeof(char));
        printf("duracion de tarea, entre 10 y 100\n");
        scanf("%d", &duracion);
        while (duracion < 10 || duracion > 100)
        {
            printf("duracion de tarea, entre 10 y 100\n");
            scanf("%d", &duracion);
        }
        nuevaTarea.Duracion = duracion;
        Tnodo *nuevoNodo = CrearNodo(nuevaTarea);
        InsertarNodo(&Start, nuevoNodo);

        printf("anadir otra? 1:si 0:no\n");
        scanf("%d", &continuar);
    }

    return 0;
}

Tnodo *CrearListaVacia()
{
    return NULL;
}
Tnodo *CrearNodo(Tarea dato)
{
    Tnodo *nodo = (Tnodo *)malloc(sizeof(Tnodo));
    nodo->T = dato;
    nodo->siguiente = NULL;
    return nodo;
}
void InsertarNodo(Tnodo **Start, Tnodo *Nodo)
{
    Nodo->siguiente = *Start;
    *Start = Nodo;
}