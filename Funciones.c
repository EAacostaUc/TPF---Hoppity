#include <stdio.h>
#include <time.h>
#include <math.h>
#include "FunDeclaraciones.h"


/*
    Se utiliza esta función void para poder limpiar el buffer y así no tener incovenientes de loops infinitos.
*/
void consumirNuevaLinea(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != EOF && c != '\n');
}


/*
Esta funcion imprime el tablero actual con movimientos ya hechos
*/
void tableroActualizado (char tablero[17][17]) {

     // imprime tablero con los ya movimientos realizados.

        printf ("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16");  // Enumera la parte de arriba del tablero.
        for (int i = 1; i <= 16; i++) {
            printf ("\n\n ");
            printf("%d\t",i);

            for (int j = 1; j <= 16; j++) {

                printf ("%c\t", tablero [i][j]);

        }
    }

}

/*
Cuando el usuario eliga la opción '2', que es la de elegir cómo será el comienzo del juego, luego si elige '1' (que sea de forma aleatoria el turno)
esta función azar_1 lo que hará es permitir elegir al ususario que sea de forma aleatoria o no el color de su ficha a jugar.
*/
int azar_1 (int inicio, int color) {  // esta función se revisa si el turno le pertenece al ususario.

    printf ("\nQuieres que se eliga de forma aleatoria el color de la ficha?\nIntroduzca '1' si quieres, sino introduzca '2': ");   scanf ("%i", &inicio);
            while (inicio != 1 && inicio != 2)
                {
                    consumirNuevaLinea();
                    printf ("Ingrese los valores correctos (1 o 2): "); scanf ("%i", &inicio);
                }
	            if (inicio == 1)
		        {
		            srand (time (NULL));
		            color = (rand () % 2) + 1;

		            if (color == 1)
        		    {
              		    printf ("\nEmpieza usted.\nJuega con fichas negras");
        		    }
		            else
        		    {
        		        printf ("\nEmpieza usted.\nJuega con fichas blancas");
        		    }
		        }
	            else
		        {

		            printf ("\nEliga el color de la ficha que va a jugar.\nIntroduzca '1' para (Negra) sino, '2' para (Blanca): "); scanf ("%i", &color);
                    while (color != 1 && color != 2)
                    {
                        consumirNuevaLinea();
                        printf ("Ingrese los valores correctos (1 o 2): "); scanf ("%i", &color);
                    }

        		    if (color == 1)
        		    {
        		        printf ("\nEmpieza usted.\nJuega con fichas negras");
        		    }
        		    else
        		    {
        		        printf ("\nEmpieza usted.\nJuega con fichas blancas");
        		    }
		        }
    return color;
}

/*
Esta función azar_2 lo que hará es permitir elegir al ususario que sea de forma aleatoria o no el color de la ficha que jugará la maquina.
*/
int azar_2 (int inicio, int color) {
    printf ("\nQuieres que se eliga de forma aleatoria el color de la ficha?\nIntroduzca '1' si quieres, sino introduzca '2': ");   scanf ("%i", &inicio);
                while (inicio != 1 && inicio != 2)
                {
                    consumirNuevaLinea();
                    printf ("Ingrese los valores correctos (1 o 2): "); scanf ("%i", &inicio);
                }
	            if (inicio == 1)
		        {
		            srand (time (NULL));
		            color = (rand () % 2) + 1;

		            if (color == 1)
        		    {
              		    printf ("\nEmpieza la maquina.\nJuega con fichas negras");
        		    }
		            else
        		    {
        		        printf ("\nEmpieza la maquina.\nJuega con fichas blancas");
        		    }
		        }
	            else
		        {

		            printf ("\nEliga el color de la ficha para la maquina.\nIntroduzca '1' para (Negra) sino, '2' para (Blanca): "); scanf ("%i", &color);
                    while (color != 1 && color != 2)
                    {
                        consumirNuevaLinea();
                        printf ("Ingrese los valores correctos (1 o 2): "); scanf ("%i", &color);
                    }

        		    if (color == 1)
        		    {
        		        printf ("\nEmpieza la maquina.\nJuega con fichas negras");
        		    }
        		    else
        		    {
        		        printf ("\nEmpieza la maquina.\nJuega con fichas blancas");
        		    }
		        }
	return color;
}

/*
Esta función se encargará de pedir (dependiendo del color de la ficha) la posición actual de la ficha elegida
, posteriormente pide ingresar la nueva posición a la que se moverá la ficha elegida.
*/

void pedidos (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva) {
        printf ("\n\n\nIngrese la posicion actual de la ficha a mover.\n\n");
        printf ("Ingrese fila actual: "); scanf ("%i", fila_actual);
        printf ("Ingrese columna actual: "); scanf ("%i", colum_actual);

        printf ("\n\nIngrese la posicion a la que quiere mover la ficha elegida.\n\n");
        printf ("Ingrese fila nueva: "); scanf ("%i", fila_nueva);
        printf ("Ingrese columna nueva: "); scanf ("%i", colum_nueva);
}





/*
Esta función se encargará de reemplazar la posición actual que contiene a la ficha a mover por '.' (punto/ posición libre)
y la posición nueva que contiene a '.' (punto/ posición libre) será reemplazado por aux (aux contiene a la ficha, ya sea N o B)
*/

void cambioDePosicionHumano (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int aux, char tablero[17][17]){
    aux = tablero [*fila_actual][*colum_actual];  // se le asigna "aux" lo que contiene el tablero en esa posicion (contiene a la ficha).
    tablero [*fila_actual][*colum_actual] = '.';  // lo que estaba en esa posicion se reemplazará por "." (punto/vacio).
    tablero [*fila_nueva][*colum_nueva] = aux;   // posición a la que se quiere mover se le asigna la ficha elegida (se mueve a la nueva posicion la ficha)

}


/*
Esta función genera numeros aleatorios desde 1 hasta 16.
*/

void aleatorioMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1) {

    *fila_actual1 = 1 + rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
    *colum_actual1 = 1 + rand() % 16;
    *colum_nueva1 = 1 + rand() % 16;
    *fila_nueva1 = 1 + rand() % 16;

}



/* Esta funcion se revisa solamente cuando la maquina juega con blancas...

Aca se generan numeros aleatorios hasta que se cumpla la condicion para poder hacer moviminetos validos
por parte de la maquina.

*/
void juegaMaquinaB (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[17][17]) {

	while ((( (tablero [*fila_actual1][*colum_actual1] != 'B') || (tablero [*fila_nueva1][*colum_nueva1] != '.'))
	    || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 2))

	    || ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1+1][*colum_actual1+1] != 'N' || tablero [*fila_actual1+1][*colum_actual1+1] != 'B') && *fila_actual1 > *fila_nueva1 && *colum_actual1 > *colum_nueva1  && *fila_actual1+2 != *fila_nueva1 && *colum_actual1+2 != *colum_nueva1)
	    ||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1+1][*colum_actual1-1] != 'N' || tablero [*fila_actual1+1][*colum_actual1-1] != 'B') && *fila_actual1 > *fila_nueva1 && *colum_actual1 < *colum_nueva1 && *fila_actual1+2 != *fila_nueva1 && *colum_actual1-2 != *colum_nueva1)
		||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1+1][*colum_actual1] != 'N' || tablero [*fila_actual1+1][*colum_actual1] != 'B')   && *fila_actual1 > *fila_nueva1 && *colum_actual1 != *colum_nueva1 && *fila_actual1+2 != *fila_nueva1 && *colum_actual1 != *colum_nueva1)
	    ||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1-1][*colum_actual1+1] != 'N' || tablero [*fila_actual1-1][*colum_actual1+1] != 'B') && *fila_actual1 < *fila_nueva1 && *colum_actual1 > *colum_nueva1 && *fila_actual1-2 != *fila_nueva1 && *colum_actual1+2 != *colum_nueva1)
		||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1-1][*colum_actual1-1] != 'N' || tablero [*fila_actual1-1][*colum_actual1-1] != 'B') && *fila_actual1 < *fila_nueva1 && *colum_actual1 < *colum_nueva1 && *fila_actual1-2 != *fila_nueva1 && *colum_actual1-2 != *colum_nueva1)
		||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1-1][*colum_actual1] != 'N' || tablero [*fila_actual1-1][*colum_actual1] != 'B')   && *fila_actual1 < *fila_nueva1 && *colum_actual1 != *colum_nueva1 && *fila_actual1-2 != *fila_nueva1 && *colum_actual1 != *colum_nueva1)
	    ||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1][*colum_actual1+1] != 'N' || tablero [*fila_actual1][*colum_actual1+1] != 'B')   && *fila_actual1 != *fila_nueva1 && *colum_actual1 > *colum_nueva1 && *fila_actual1 != *fila_nueva1 && *colum_actual1+2 != *colum_nueva1)
		||  ((pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2) > 8) && (tablero [*fila_actual1][*colum_actual1-1] != 'N' || tablero [*fila_actual1][*colum_actual1-1] != 'B')   && *fila_actual1 != *fila_nueva1 && *colum_actual1 < *colum_nueva1 && *fila_actual1 != *fila_nueva1 && *colum_actual1-2 != *colum_nueva1)
	    )
    {
        *fila_actual1 = 1 + rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = 1 + rand() % 16;
        *colum_nueva1 = 1 + rand() % 16;
        *fila_nueva1 = 1 + rand() % 16;

    }
}



/* Esta funcion se revisa solamente cuando la maquina juega con negras...

Aca se generan numeros aleatorios hasta que se cumpla la condicion para poder hacer moviminetos validos
por parte de la maquina.

*/

void juegaMaquinaN (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, char tablero[17][17]) {

    while ((tablero [*fila_actual1][*colum_actual1] != 'N') || (tablero [*fila_nueva1][*colum_nueva1] != '.')
    || (pow((*fila_nueva1 - *fila_actual1), 2) + pow((*colum_nueva1 - *colum_actual1), 2)) > 2)   // en el calculo le puse que sea > 8 para que haga tambien los saltos
    {
        *fila_actual1 = 1 + rand() % 16;       // Genera numeros aleatorios a partir del 1 hasta 16.
        *colum_actual1 = 1 + rand() % 16;
        *colum_nueva1 = 1 + rand() % 16;
        *fila_nueva1 = 1 + rand() % 16;

    }
}



/*
Esta función se encargará de reemplazar la posición actual que contiene a la ficha a mover por '.' (punto/ posición libre)
y la posición nueva que contiene a '.' (punto/ posición libre) será reemplazado por aux2 (aux2 contiene a la ficha, ya sea N o B)

Esta funcion se revisa despues de que se revise, ya sea juegaMaquinaN o juegaMaquinaB...
cuando tenga las coordenadas correctas.

*/

void cambioDePosicionMaquina (int *fila_actual1, int *colum_actual1, int *fila_nueva1, int *colum_nueva1, int aux2, char tablero[17][17]){
    aux2 = tablero [*fila_actual1][*colum_actual1];  // se le asigna "aux" lo que contiene el tablero en esa posicion (contiene a la ficha).
    tablero [*fila_actual1][*colum_actual1] = '.';  // lo que estaba en esa posicion se reemplazará por "." (punto/vacio).
    tablero [*fila_nueva1][*colum_nueva1] = aux2;   // posición a la que se quiere mover se le asigna la ficha elegida (se mueve a la nueva posicion la ficha)

}



/*
Esta función se encargará de hacer los saltos de las fichas, saltar sobre otra ficha ya sea propia o del oponente.

Verifica que alrededor de la ficha que se quiere mover haya alguna ficha ya sea propia o del oponente, todos los que estan adyacentes a él
si es que encuentra uno, se hace el cambio de posición.

Salta fichas y de paso ya hace el cambio de posiciones...
*/

void saltarFichas (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int *x, int aux, char tablero[17][17]) {

    //PROBLEMA, cuando mete un movimiento simple despues del salto fallido no para el ciclo...

    if (((tablero [*fila_actual+1][*colum_actual+1] == 'N' || tablero [*fila_actual+1][*colum_actual+1] == 'B') && *fila_actual < *fila_nueva && *colum_actual < *colum_nueva  && *fila_actual+2==*fila_nueva && *colum_actual+2==*colum_nueva)
    ||  ((tablero [*fila_actual+1][*colum_actual-1] == 'N' || tablero [*fila_actual+1][*colum_actual-1] == 'B') && *fila_actual < *fila_nueva && *colum_actual > *colum_nueva && *fila_actual+2==*fila_nueva && *colum_actual-2==*colum_nueva)
	||  ((tablero [*fila_actual+1][*colum_actual] == 'N' || tablero [*fila_actual+1][*colum_actual] == 'B') 	&& *fila_actual < *fila_nueva && *colum_actual == *colum_nueva && *fila_actual+2==*fila_nueva && *colum_actual==*colum_nueva)
    ||  ((tablero [*fila_actual-1][*colum_actual+1] == 'N' || tablero [*fila_actual-1][*colum_actual+1] == 'B') && *fila_actual > *fila_nueva && *colum_actual < *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual+2==*colum_nueva)
	||  ((tablero [*fila_actual-1][*colum_actual-1] == 'N' || tablero [*fila_actual-1][*colum_actual-1] == 'B') && *fila_actual > *fila_nueva && *colum_actual > *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual-2==*colum_nueva)
	||  ((tablero [*fila_actual-1][*colum_actual] == 'N' || tablero [*fila_actual-1][*colum_actual] == 'B') 	&& *fila_actual > *fila_nueva && *colum_actual == *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual==*colum_nueva)
    ||  ((tablero [*fila_actual][*colum_actual+1] == 'N' || tablero [*fila_actual][*colum_actual+1] == 'B') 	&& *fila_actual == *fila_nueva && *colum_actual < *colum_nueva && *fila_actual==*fila_nueva && *colum_actual+2==*colum_nueva)
	||  ((tablero [*fila_actual][*colum_actual-1] == 'N' || tablero [*fila_actual][*colum_actual-1] == 'B') 	&& *fila_actual == *fila_nueva && *colum_actual > *colum_nueva && *fila_actual==*fila_nueva && *colum_actual-2==*colum_nueva)
    ) {

            cambioDePosicionHumano (fila_actual, colum_actual, fila_nueva, colum_nueva, aux, tablero);
            *x = 1;

    } else {
        *x = 0;
    }

}





void volverAsaltar (int *fila_actual, int *colum_actual, int *fila_nueva, int *colum_nueva, int aux3, char tablero[17][17]) {
    int opcion = 1, bandera = 0, cont = 0;

    while (opcion == 1 && (*fila_actual >= 1 && *fila_actual <= 16) && (*colum_actual >= 1 && *colum_actual <= 16) && (*fila_nueva >= 1 && *fila_nueva <= 16) && (*colum_nueva >= 1 && *colum_nueva <= 16)
        && ((pow((*fila_nueva - *fila_actual), 2) + pow((*colum_nueva - *colum_actual), 2)) <= 8)) {


        // la condicion dentro del if es para que no haga un salto encima de una casilla vacia...

        if (((tablero [*fila_actual+1][*colum_actual+1] == 'N' || tablero [*fila_actual+1][*colum_actual+1] == 'B') && *fila_actual < *fila_nueva && *colum_actual < *colum_nueva  && *fila_actual+2==*fila_nueva && *colum_actual+2==*colum_nueva)
    ||  ((tablero [*fila_actual+1][*colum_actual-1] == 'N' || tablero [*fila_actual+1][*colum_actual-1] == 'B') && *fila_actual < *fila_nueva && *colum_actual > *colum_nueva && *fila_actual+2==*fila_nueva && *colum_actual-2==*colum_nueva)
	||  ((tablero [*fila_actual+1][*colum_actual] == 'N' || tablero [*fila_actual+1][*colum_actual] == 'B') 	&& *fila_actual < *fila_nueva && *colum_actual == *colum_nueva && *fila_actual+2==*fila_nueva && *colum_actual==*colum_nueva)
    ||  ((tablero [*fila_actual-1][*colum_actual+1] == 'N' || tablero [*fila_actual-1][*colum_actual+1] == 'B') && *fila_actual > *fila_nueva && *colum_actual < *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual+2==*colum_nueva)
	||  ((tablero [*fila_actual-1][*colum_actual-1] == 'N' || tablero [*fila_actual-1][*colum_actual-1] == 'B') && *fila_actual > *fila_nueva && *colum_actual > *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual-2==*colum_nueva)
	||  ((tablero [*fila_actual-1][*colum_actual] == 'N' || tablero [*fila_actual-1][*colum_actual] == 'B') 	&& *fila_actual > *fila_nueva && *colum_actual == *colum_nueva && *fila_actual-2==*fila_nueva && *colum_actual==*colum_nueva)
    ||  ((tablero [*fila_actual][*colum_actual+1] == 'N' || tablero [*fila_actual][*colum_actual+1] == 'B') 	&& *fila_actual == *fila_nueva && *colum_actual < *colum_nueva && *fila_actual==*fila_nueva && *colum_actual+2==*colum_nueva)
	||  ((tablero [*fila_actual][*colum_actual-1] == 'N' || tablero [*fila_actual][*colum_actual-1] == 'B') 	&& *fila_actual == *fila_nueva && *colum_actual > *colum_nueva && *fila_actual==*fila_nueva && *colum_actual-2==*colum_nueva) ){

            printf ("\nQuiere hacer otro salto con la misma ficha? Ingrese '1' si quiere o '2' si no quiere: "); scanf ("%i", &opcion);

            if (cont != 0){  // la primera ez que entra en esta funcion cont = 0, porque no queremos que bandera = 1.
            	bandera = 1; // bandera será igual a 1 cuando se vuelva a repetir el ciclo la segunda vez.
            }

            if (bandera == 1) {  // esto seria para el cambio de posiciones

                aux3 = tablero [*fila_actual][*colum_actual];  // se le asigna "aux" lo que contiene el tablero en esa posicion (contiene a la ficha).
				tablero [*fila_actual][*colum_actual] = '.';  // lo que estaba en esa posicion se reemplazará por "." (punto/vacio).
                tablero [*fila_nueva][*colum_nueva] = aux3;  // aux3 contiene la ficha.

            }

            if (opcion == 1){ // solo cuando opcion = 1, cuando opcion = 2 volveria a mostrar el tablero
                tableroActualizado (tablero);
            }

            bandera = 1;

        } else {

            printf ("\nNo se puede realizar movimiento, vuelva a intentar\n");
            bandera = 0;
            cont++; // cuando los movimientos sean erroneos, cont aumenta asi para que cuando vuelva a repetirse el ciclo "bandera" ya sea 1.
        }


        if (opcion == 1) {


            if (bandera == 1){
            	*fila_actual = *fila_nueva;
            	*colum_actual = *colum_nueva;
            }

            printf ("\n\nIngrese la nueva posicion a la que quiere mover otra vez la misma ficha.\n\n");
            printf ("Ingrese fila nueva: "); scanf ("%i", fila_nueva);
            printf ("Ingrese columna nueva: "); scanf ("%i", colum_nueva);

        }

    }

}

/* La funcion sirve para hacer una revision despues de cada jugada y ver si todas las fichas ya sea "N" o "B"
 * estan todas colocadas en el campamento enemigo.
 */
int condicionQuienGana (char tablero[17][17]) {
	int cont = 1;
	//Condición de terminar la partida; cuando todas las fichas llegan al campamento de la zona opuesta.

	    for (int i = 0; i <= 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j <= 16; j++) {
	                                            // Revisión del campo de las fichas negras.
	            if (i<=5 && j == 1 && i>0 && tablero [i][j] == 'B')
	                cont++;
	            if (i<=5 && j == 2 && i>0 && tablero [i][j] == 'B')
	                cont++;
	            if (i<=4 && j == 3 && i>0 && tablero [i][j] == 'B')
	                cont++;
	            if (i<=3 && j == 4 && i>0 && tablero [i][j] == 'B')
	                cont++;
	            if (i<=2 && j == 5 && i>0 && tablero [i][j] == 'B')
	                cont++;
	        }
	    }
	    if (cont == 20){
	        printf ("\n\nHa ganado las blancas.");
	        consumirNuevaLinea();
	        return cont;
	        //break;
	    }
	    else {
	        cont = 1;
	    }

	    for (int i = 0; i <= 16; i++) {         //Recorremos la matriz
	        for (int j = 0; j <= 16; j++) {
	                                            // Revisión del campo de las fichas blancas.
	             if (i==16 && j>=12 && tablero [i][j] == 'N')
	                cont++;
	             if (i==15 && j>=12 && tablero [i][j] == 'N')
	                cont++;
	             if (i==14 && j>=13 && tablero [i][j] == 'N')
	                cont++;
	             if (i==13 && j>=14 && tablero [i][j] == 'N')
	                cont++;
	             if (i==12 && j>=15 && tablero [i][j] == 'N')
	                cont++;
	        }
	    }
	    if (cont == 20){
	        printf ("\n\nHa ganado las negras.");
	        consumirNuevaLinea();
	        return cont;
	        //break;
	    }
	    else {
	        cont = 1;
	    }

	    return 1;
}



/*
Esta función se encarga de verificar si los valores ingresados por el usuario son correctos
, caso contrario, te pide de vuelta los valores para ingresar
*/

int validacion (int inicio) {

    while (inicio != 1 && inicio != 2) {
        consumirNuevaLinea();
        printf ("Ingrese los valores correctos (1 o 2): "); scanf ("%i", &inicio);

    }
    return inicio;
}

