#include <iostream>



int main(int argc, char** argv) {
// Datos de los usuarios predefinidos
    int id_usuario1 = 1, id_usuario2 = 2, id_usuario3 = 3;
    char nombre_usuario1[] = "Usuario1", nombre_usuario2[] = "Usuario2", nombre_usuario3[] = "Usuario3";
    float papel_usuario1 = 0.0, plastico_usuario1 = 0.0, vidrio_usuario1 = 0.0;
    float papel_usuario2 = 0.0, plastico_usuario2 = 0.0, vidrio_usuario2 = 0.0;
    float papel_usuario3 = 0.0, plastico_usuario3 = 0.0, vidrio_usuario3 = 0.0;
    int puntos_usuario1 = 0, puntos_usuario2 = 0, puntos_usuario3 = 0;
 
    // Datos de las recompensas
    char nombre_recompensa1[] = "Descuento en tienda", nombre_recompensa2[] = "Entrada de cine", nombre_recompensa3[] = "Vale de restaurante";
    int puntos_recompensa1 = 100, puntos_recompensa2 = 200, puntos_recompensa3 = 300;
 
    while (true) {
        // Mostrar menú
        printf("Sistema de Gestion de Reciclaje\n");
        printf("1. Registrar Reciclaje\n");
        printf("2. Ver Estadisticas\n");
        printf("3. Canjear Puntos\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
 
        int opcion;
        scanf("%d", &opcion);
 
        if (opcion == 4) {
            printf("Saliendo...\n");
            break;
        }
 
        int id_usuario;
        printf("Ingrese el ID de usuario (1-3): ");
        scanf("%d", &id_usuario);
 
        if (id_usuario < 1 || id_usuario > 3) {
            printf("ID de usuario no valido.\n");
            continue;
        }
 
        // Variables de usuario seleccionadas
        char *nombre_usuario;
        float *papel_usuario, *plastico_usuario, *vidrio_usuario;
        int *puntos_usuario;
 
        if (id_usuario == id_usuario1) {
            nombre_usuario = nombre_usuario1;
            papel_usuario = &papel_usuario1;
            plastico_usuario = &plastico_usuario1;
            vidrio_usuario = &vidrio_usuario1;
            puntos_usuario = &puntos_usuario1;
        } else if (id_usuario == id_usuario2) {
            nombre_usuario = nombre_usuario2;
            papel_usuario = &papel_usuario2;
            plastico_usuario = &plastico_usuario2;
            vidrio_usuario = &vidrio_usuario2;
            puntos_usuario = &puntos_usuario2;
        } else {
            nombre_usuario = nombre_usuario3;
            papel_usuario = &papel_usuario3;
            plastico_usuario = &plastico_usuario3;
            vidrio_usuario = &vidrio_usuario3;
            puntos_usuario = &puntos_usuario3;
        }
 
        switch (opcion) {
            case 1: {
                int tipo;
                float cantidad;
 
                printf("Seleccione el tipo de material:\n");
                printf("1. Papel\n");
                printf("2. Plastico\n");
                printf("3. Vidrio\n");
                printf("Tipo: ");
                scanf("%d", &tipo);
 
                printf("Cantidad (kg): ");
                scanf("%f", &cantidad);
 
                if (tipo == 1) {
                    *papel_usuario += cantidad;
                    *puntos_usuario += static_cast<int>(cantidad * 10);
                } else if (tipo == 2) {
                    *plastico_usuario += cantidad;
                    *puntos_usuario += static_cast<int>(cantidad * 20);
                } else if (tipo == 3) {
                    *vidrio_usuario += cantidad;
                    *puntos_usuario += static_cast<int>(cantidad * 15);
                } else {
                    printf("Tipo no valido.\n");
                    continue;
                }
 
                printf("Reciclaje registrado con exito.\n");
                break;
            }
            case 2:
                printf("Estadisticas de Reciclaje para %s:\n", nombre_usuario);
                printf("Papel: %.2f kg\n", *papel_usuario);
                printf("Plastico: %.2f kg\n", *plastico_usuario);
                printf("Vidrio: %.2f kg\n", *vidrio_usuario);
                printf("Puntos acumulados: %d\n", *puntos_usuario);
                break;
            case 3: {
                printf("Recompensas disponibles:\n");
                printf("1. %s - %d puntos\n", nombre_recompensa1, puntos_recompensa1);
                printf("2. %s - %d puntos\n", nombre_recompensa2, puntos_recompensa2);
                printf("3. %s - %d puntos\n", nombre_recompensa3, puntos_recompensa3);
 
                int opcion_recompensa;
                printf("Seleccione una recompensa: ");
                scanf("%d", &opcion_recompensa);
 
                int puntos_requeridos;
                char *nombre_recompensa;
                if (opcion_recompensa == 1) {
                    puntos_requeridos = puntos_recompensa1;
                    nombre_recompensa = nombre_recompensa1;
                } else if (opcion_recompensa == 2) {
                    puntos_requeridos = puntos_recompensa2;
                    nombre_recompensa = nombre_recompensa2;
                } else if (opcion_recompensa == 3) {
                    puntos_requeridos = puntos_recompensa3;
                    nombre_recompensa = nombre_recompensa3;
                } else {
                    printf("Seleccion no valida.\n");
                    continue;
                }
 
                if (*puntos_usuario >= puntos_requeridos) {
                    *puntos_usuario -= puntos_requeridos;
                    printf("Has canjeado %s.\n", nombre_recompensa);
                } else {
                    printf("No tienes suficientes puntos para canjear esta recompensa.\n");
                }
                break;
            }
            default:
                printf("Opcion no valida.\n");
                break;
        }
    }

	return 0;
}
