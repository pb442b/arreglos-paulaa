#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definimos constantes
#define MAX_PRODS 10
#define MAX_NAME_LEN 50

// Prototipos de funciones
void ingresar_datos(char productos[][MAX_NAME_LEN], float precios[], int n);
float calcular_precio_total(float precios[], int n);
void encontrar_mas_caro_barato(char productos[][MAX_NAME_LEN], float precios[], int n, char mas_caro[], char mas_barato[]);
float calcular_precio_promedio(float precios[], int n);
float buscar_producto(char productos[][MAX_NAME_LEN], float precios[], int n, char nombre[]);

#endif
