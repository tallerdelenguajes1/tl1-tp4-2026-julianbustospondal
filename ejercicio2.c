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
Tnodo *QuitarNodo(Tnodo **Start, int idBuscado);
Tnodo *BuscarNodo(Tnodo *Start, int IdBuscado);
Tnodo *BuscarNodoPalabra(Tnodo *Start, char *busqueda);
void MostrarLista(Tnodo *Start);
void LiberarLista(Tnodo **Start);
int main()
{
    int continuar = 1;
    int duracion;
    int id = 1000;
    int eleccionBusqueda;
    Tnodo *ListaPendientes = CrearListaVacia();
    Tnodo *ListaRealizadas = CrearListaVacia();
    char descriptemp[100];
    while (continuar == 1)
    {
        Tarea nuevaTarea;
        nuevaTarea.TareaID = id;
        id++;

        printf("describir tarea\n");
        scanf(" %[^\n]", descriptemp);
        nuevaTarea.Descripcion = (char *)malloc((strlen(descriptemp) + 1) * sizeof(char));
        strcpy(nuevaTarea.Descripcion, descriptemp);
        printf("duracion de tarea, entre 10 y 100\n");
        scanf("%d", &duracion);
        while (duracion < 10 || duracion > 100)
        {
            printf("duracion de tarea, entre 10 y 100\n");
            scanf("%d", &duracion);
        }
        nuevaTarea.Duracion = duracion;
        Tnodo *nuevoNodo = CrearNodo(nuevaTarea);
        InsertarNodo(&ListaPendientes, nuevoNodo);

        printf("anadir otra? 1:si 0:no\n");
        scanf("%d", &continuar);
    }
    continuar = 1;
    while (continuar == 1 && ListaPendientes != NULL)
    {
        printf("\n--- TAREAS PENDIENTES ACTUALES ---\n");
        MostrarLista(ListaPendientes);

        int idAMover;
        printf("\nIngrese el ID de la tarea que ya realizo: ");
        scanf("%d", &idAMover);
        Tnodo *nodoSuelto = QuitarNodo(&ListaPendientes, idAMover);
        if (nodoSuelto != NULL)
        {

            InsertarNodo(&ListaRealizadas, nodoSuelto);
            printf("Tarea %d movida a realizadas!\n", idAMover);
        }
        else
        {
            printf("No se encontro una tarea con el ID %d.\n", idAMover);
        }

        if (ListaPendientes != NULL)
        {
            printf("\nMover otra tarea? (1: Si / 0: No): ");
            scanf("%d", &continuar);
        }
        else
        {
            printf("\nNo quedan tareas pendientes.\n");
        }
    }

    printf("       REPORTE FINAL         \n");
    printf(" PENDIENTES:\n");
    MostrarLista(ListaPendientes);
    printf("\n REALIZADAS:\n");
    MostrarLista(ListaRealizadas);
    int continuar1 = 0;
    while (continuar1 == 0)
    {

        printf("mostrar tarea. por ID:0 / por Nombre:1\n");
        scanf("%d", &eleccionBusqueda);
        if (eleccionBusqueda == 0)
        {
            int IdBusqueda;
            printf("indtroduzca ID:\n");
            scanf("%d", &IdBusqueda);
            Tnodo *BusquedaId = BuscarNodo(ListaPendientes, IdBusqueda);
            Tnodo *BusquedaId2 = BuscarNodo(ListaRealizadas, IdBusqueda);
            if (BusquedaId != NULL)
            {
                printf("  [ID: %d] %s (Duracion: %d) Tarea Pendiente\n", BusquedaId->T.TareaID, BusquedaId->T.Descripcion, BusquedaId->T.Duracion);
            }
            else if (BusquedaId2 != NULL)
            {
                printf("  [ID: %d] %s (Duracion: %d) Tarea Realizada\n", BusquedaId2->T.TareaID, BusquedaId2->T.Descripcion, BusquedaId2->T.Duracion);
            }
            else
            {
                printf("No se encontro ningun ID\n");
            }
        }
        else if (eleccionBusqueda == 1)
        {
            char PalabraClave[50];
            printf("indtroduzca nombre:\n");
            scanf(" %[^\n]", PalabraClave);
            Tnodo *BusquedaNombre = BuscarNodoPalabra(ListaPendientes, PalabraClave);
            Tnodo *BusquedaNombre2 = BuscarNodoPalabra(ListaRealizadas, PalabraClave);
            if (BusquedaNombre != NULL)
            {
                printf("  [ID: %d] %s (Duracion: %d) Tarea Pendiente\n", BusquedaNombre->T.TareaID, BusquedaNombre->T.Descripcion, BusquedaNombre->T.Duracion);
            }
            else if (BusquedaNombre2 != NULL)
            {
                printf("  [ID: %d] %s (Duracion: %d) Tarea Realizada\n", BusquedaNombre2->T.TareaID, BusquedaNombre2->T.Descripcion, BusquedaNombre2->T.Duracion);
            }
            else
            {
                printf("No se encontro esa palabra\n");
            }
        }
        else
        {
            printf("valor incorrecto\n");
        }
        printf("desea consultar de nuevo? si:0 no:1\n");
        scanf("%d", &continuar1);
    }
    LiberarLista(&ListaRealizadas);
    LiberarLista(&ListaPendientes);
    return 0;
}
// -----------------------------------------------Funciones----------------------------------------------------------------------------------------------------
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
Tnodo *QuitarNodo(Tnodo **Start, int idBuscado)
{
    Tnodo *nodoAux = (*Start);
    Tnodo *nodoAnt = NULL;

    while (nodoAux != NULL && nodoAux->T.TareaID != idBuscado)
    {
        nodoAnt = nodoAux;
        nodoAux = nodoAux->siguiente;
    }

    if (nodoAux != NULL)
    {
        if (nodoAux == (*Start))
        {
            (*Start) = nodoAux->siguiente;
        }
        else
        {
            nodoAnt->siguiente = nodoAux->siguiente;
        }
        nodoAux->siguiente = NULL;
    }

    return nodoAux;
}
void MostrarLista(Tnodo *Start)
{
    Tnodo *Aux = Start;
    if (Aux == NULL)
    {
        printf("  (La lista esta vacia)\n");
        return;
    }
    while (Aux != NULL)
    {
        printf("  [ID: %d] %s (Duracion: %d)\n", Aux->T.TareaID, Aux->T.Descripcion, Aux->T.Duracion);
        Aux = Aux->siguiente;
    }
}
void LiberarLista(Tnodo **Start)
{
    Tnodo *Actual = *Start;
    Tnodo *Siguiente = NULL;

    while (Actual != NULL)
    {
        Siguiente = Actual->siguiente;

        free(Actual->T.Descripcion);

        free(Actual);

        Actual = Siguiente;
    }
    *Start = NULL;
}
Tnodo *BuscarNodoPalabra(Tnodo *Start, char *busqueda)
{
    Tnodo *Aux = Start;
    while (Aux != NULL)
    {
        if (strstr(Aux->T.Descripcion, busqueda) != NULL)
        {
            return Aux;
        }
        Aux = Aux->siguiente;
    }
    return NULL;
}
Tnodo *BuscarNodo(Tnodo *Start, int IdBuscado)
{
    Tnodo *Aux = Start;
    while (Aux != NULL)
    {
        if (Aux->T.TareaID == IdBuscado)
        {
            return Aux;
        }
        Aux = Aux->siguiente;
    }
    return NULL;
}