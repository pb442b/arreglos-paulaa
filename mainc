#include <stdio.h>
#include "funciones.h"

int main() {
    char productos[MAX_PRODS][MAX_NAME_LEN];
    float precios[MAX_PRODS];
    char mas_caro[MAX_NAME_LEN], mas_barato[MAX_NAME_LEN];
    int n;

    printf("¿Cuántos productos quieres ingresar (máximo %d)? ", MAX_PRODS);
    scanf("%d", &n);

    // Verificamos que el número de productos no exceda el límite
    if (n > MAX_PRODS || n <= 0) {
        printf("Número de productos no válido.\n");
        return 1;
    }

    ingresar_datos(productos, precios, n);

    // Calculamos el total del inventario
    float total = calcular_precio_total(precios, n);
    printf("El precio total del inventario es: %.2f\n", total);

    // Encontramos el producto más caro y más barato
    encontrar_mas_caro_barato(productos, precios, n, mas_caro, mas_barato);
    printf("El producto más caro es: %s\n", mas_caro);
    printf("El producto más barato es: %s\n", mas_barato);

    // Calculamos el precio promedio
    float promedio = calcular_precio_promedio(precios, n);
    printf("El precio promedio es: %.2f\n", promedio);

    // Búsqueda de producto por nombre
    char nombre_busqueda[MAX_NAME_LEN];
    printf("Ingresa el nombre del producto que deseas buscar: ");
    getchar();  // Limpiamos el buffer de salto de línea
    fgets(nombre_busqueda, MAX_NAME_LEN, stdin);
    nombre_busqueda[strcspn(nombre_busqueda, "\n")] = 0; // Eliminamos el salto de línea

    float precio_busqueda = buscar_producto(productos, precios, n, nombre_busqueda);
    if (precio_busqueda != -1) {
        printf("El precio del producto %s es: %.2f\n", nombre_busqueda, precio_busqueda);
    } else {
        printf("Producto no encontrado.\n");
    }

    return 0;
}
