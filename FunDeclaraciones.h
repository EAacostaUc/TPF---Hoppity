#ifndef FUNDECLARACIONES_H_
#define FUNDECLARACIONES_H_


//Declaraciones de las funciones...

void consumirNuevaLinea(void);

int azar_1 (int inicio, int color);

int azar_2 (int inicio, int color);

void pedidos (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva);

void cambioDePosicionHumano (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int aux, char tablero[17][17]);

void aleatorioMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1);

void juegaMaquinaB (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[17][17]);

void juegaMaquinaN (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[17][17]);

void cambioDePosicionMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, int aux2, char tablero[17][17]);

void saltarFichas (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int *x, int aux, char tablero[17][17]);

void volverAsaltar (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int aux3, char tablero[17][17]);

int condicionQuienGana (char tablero[17][17]);

int validacion (int inicio);


#endif /* FUNDECLARACIONES_H_ */
