Trabajo Práctico 4 (TP4)

Considere la siguiente situación: En la misma distribuidora del práctico anterior, ahora surgió la necesidad de llevar un control de las tareas realizadas por sus empleados. Usted forma parte del equipo de programación que se encargará de hacer el módulo en cuestión, que a partir de ahora se llamará módulo To-Do.

Tareas
Cada empleado tiene un listado de tareas a realizar y debe indicar en el sistema si fueron realizadas o no. Para ello, deberá crear dos listas enlazadas:

Una para las tareas pendientes.

Otra para las tareas realizadas.

Cada vez que se marque una tarea como realizada, deberá mover la tarea de la lista de tareas pendientes a la lista de tareas realizadas.


Las estructuras de datos necesarias son las siguientes:
typedef struct Tarea { 
    int TareaID;       // Numérico autoincremental comenzando en 1000 
    char *Descripcion; // Descripción de la tarea      
    int Duracion;      // Entre 10 – 100  
} Tarea;  

typedef struct Nodo { 
    Tarea T;  
    struct Nodo *Siguiente;  
} Nodo;

Requerimientos
Interfaz de Carga: Desarrolle una interfaz de carga de tareas para solicitar tareas pendientes, en la cual se solicite descripción y duración de la misma (el ID debe ser generado automáticamente por el sistema, de manera autoincremental comenzando desde el número 1000). Al cabo de cada tarea, consulte al usuario si desea ingresar una nueva tarea o finalizar la carga.

Transferencia de Tareas: Implemente una interfaz para elegir qué tareas de la lista de pendientes deben ser transferidas a la lista de tareas realizadas.

Listado de Tareas: Implemente una funcionalidad que permita listar todas las tareas pendientes y realizadas.

Búsqueda: Implemente una funcionalidad que permita consultar tareas por ID o palabra clave y mostrarlas por pantalla, indicando si corresponde a una tarea pendiente o realizada.