# Trabajo Práctico 4: Módulo To-Do (Tareas) 

Este repositorio contiene la resolución del Trabajo Práctico N° 4, enfocado en el desarrollo de un módulo de gestión de tareas utilizando **Listas Enlazadas simples en C**.

##  Descripción del Problema

En la misma distribuidora del práctico anterior, ha surgido la necesidad de llevar un control de las tareas realizadas por sus empleados. Este proyecto implementa el **módulo To-Do**, donde cada empleado tiene un listado de tareas a realizar y debe indicar en el sistema si fueron realizadas o no.

El sistema maneja el estado de las tareas mediante dos listas enlazadas:
1. **Tareas Pendientes**
2. **Tareas Realizadas**

Cada vez que se marca una tarea como realizada, el sistema se encarga de extraer el nodo de la lista de pendientes y reinsertarlo en la lista de realizadas.

##  Estructuras de Datos

El sistema utiliza las siguientes estructuras en C para modelar los datos:

```c
typedef struct Tarea { 
    int TareaID;       // Numérico autoincremental comenzando en 1000 
    char *Descripcion; // Texto dinámico
    int Duracion;      // Valor entre 10 y 100
} Tarea;

typedef struct Nodo { 
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;
```

##  Requisitos y Funcionalidades

El proyecto cumple con los siguientes requerimientos solicitados:

- [x] **Interfaz de Carga de Tareas:** Solicita la descripción y duración de tareas pendientes. El `TareaID` es generado automáticamente por el sistema de manera autoincremental desde el 1000. Al finalizar cada tarea, se consulta al usuario si desea ingresar una nueva o finalizar.
- [x] **Transferencia de Estado:** Interfaz que permite elegir, mediante el ID, qué tareas de la lista de pendientes deben ser movidas a la lista de tareas realizadas.
- [x] **Listado General:** Funcionalidad para imprimir por pantalla el reporte final mostrando todas las tareas pendientes y realizadas.
- [x] **Búsqueda Avanzada:** Funcionalidad que permite consultar tareas por ID o palabra clave, mostrándolas por pantalla e indicando en qué lista se encuentran actualmente (Pendiente o Realizada).