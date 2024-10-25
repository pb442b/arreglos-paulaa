#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresar_datos(char productos[][MAX_NAME_LEN], float precios[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Ingresa el nombre del producto %d: ", i + 1);
        getchar();  // Limpiamos el buffer del salto de línea anterior
        fgets(productos[i], MAX_NAME_LEN, stdin);
        productos[i][strcspn(productos[i], "\n")] = 0; // Eliminamos el salto de línea al final del string

        // Validamos que el precio no sea negativo
        do {
            printf("Ingresa el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) {
                printf("El precio no puede ser negativo. Inténtalo de nuevo.\n");
            }
        } while (precios[i] < 0);
    }
}

float calcular_precio_total(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

void encontrar_mas_caro_barato(char productos[][MAX_NAME_LEN], float precios[], int n, char mas_caro[], char mas_barato[]) {
    int idx_caro = 0, idx_barato = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[idx_caro]) {
            idx_caro = i;
        }
        if (precios[i] < precios[idx_barato]) {
            idx_barato = i;
        }
    }
    strcpy(mas_caro, productos[idx_caro]);
    strcpy(mas_barato, productos[idx_barato]);
}

float calcular_precio_promedio(float precios[], int n) {
    float total = calcular_precio_total(precios, n);
    return total / n;
}

float buscar_producto(char productos[][MAX_NAME_LEN], float precios[], int n, char nombre[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(productos[i], nombre) == 0) {
            return precios[i];
        }
    }
    return -1;  // Producto no encontrado
}
