#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "FunDeclaraciones.h"

char tablero [17][17];

int main ()
{
    int inicio, turno, color=0, aux=0, aux2=0, aux3=0, t, fila_actual, colum_actual, fila_nueva, colum_nueva, x = 0, a = 0, result = 0;  // declaración e inicializaciones variables
    int fila_actual1, colum_actual1, fila_nueva1, colum_nueva1; // de la maquina...

    printf ("\t\t\t\tBIENVENIDO A HOPPITY\n");
    printf ("Desea comenzar de forma aleatoria? ingrense '1' si quiere, o '2' si quiere elegir: "); scanf ("%i", &inicio);
    inicio = validacion (inicio);

    srand (time (NULL));

    if (inicio == 1)
    {
        turno = (rand () % 2) + 1;

        if (turno == 1)
	    {

	    printf ("\nEmpieza usted.");
	    }
        else
	    {

	        printf ("\nEmpieza la maquina.");
	    }

        if (turno == 1 || turno == 2)
	    {

	        color = (rand () % 2) + 1;

    	    if (color == 1)
    	    {
    	        printf ("\nJuega con fichas negras");
    	    }
    	    else
    	    {
    	        printf ("\nJuega con fichas blancas");
    	    }
	    }

    }
    else if (inicio == 2)
    {
        printf ("\nQuieres que se eliga de forma aleatoria el turno?\nIntroduzca '1' si quiere, sino introduzca '2': "); scanf ("%i", &inicio);
        inicio = validacion (inicio);
        if (inicio == 1)
        {
            //srand (time (NULL));
	        turno = (rand () % 2) + 1;
	        if (turno == 1)        // Cuando turno == 1, Turno del usuario.
	        {
	            color = azar_1 (inicio, color);        // Esta función se encarga de permitir elegir que sea de forma aleatoria o no el color de las fichas.

	        }
	        else          // Cuando turno == 2, Turno de la maquina.
    	    {

        		color = azar_2 (inicio, color);
    	   }

        }
        else
	    {
	        printf ("\nDesea empezar usted? o desea que empieze la maquina.\nSi quiere empezar usted introduzca '1' sino, introduzca '2': "); scanf ("%i", &turno);
            turno = validacion (turno);
	        if (turno == 1)
	        {
	            color = azar_1 (inicio, color); // Esta función se encarga de permitir elegir al usuario que sea de forma aleatoria o no el color de su ficha.

            }
	        else
	        {
	            color = azar_2 (inicio, color); // Esta función se encarga de permitir elegir al usuario que sea de forma aleatoria o no el color de la ficha para la maquina.


	        }
	    }

    }

        for (int i = 0; i <= 16; i++) {
            for (int j = 0; j <= 16; j++) {

                /*
                Condiciones para colocar 'N' en la parte superior izquierda de la matriz en forma triangular.
                */

                if ((i<=5 && j == 1 && i>0) || (i<=5 && j == 2 && i>0) || (i<=4 && j == 3 && i>0)
                                            || (i<=3 && j == 4 && i>0) || (i<=2 && j == 5 && i>0)) {
                    tablero [i][j] = 'N';

                }

                /*
                Condiciones para colocar 'B' en la parte inferior derecha de la matriz en forma triangular.
                */

                else if ((i==16 && j>=12) || (i==15 && j>=12) || (i==14 && j>=13) || (i==13 && j>=14) || (i==12 && j>=15)) {
                        tablero [i][j] = 'B';

                }

                else {
                    tablero [i][j] = '.';
                }

            }
        }

    // Se imprime el tablero normal, con las fichas en sus posiciones antes de realizar los movimientos.

   printf ("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16"); // Enumera la parte superior del tablero.
    for (int i = 1; i <= 16; i++) {
        printf ("\n\n");
        printf("%d\t",i);  // con este se enumera el costado.

        for (int j = 1; j <= 16; j++) {

            printf ("%c\t", tablero [i][j]);

            }
        }

    /*
    Utilizamos una estructura repetitiva Do-While para que se ejecute primeramente el bloque de sentencias
    , este pedirá datos al usuario como también a la máquina (dependiendo del turno).
    Al ususario se le pedirá que ingrese los datos pedidos de forma manual, mientras que para la máquina será de forma aleatoria el ingreso
    de los datos.
    Posteriormente, te aparecerá si quieres terminar el turno (al terminar el turno el oponente hace los movimientos) o si quiere rendirse (usted), esto
    decide el usuario, dependiendo de lo que ingreses sigue el juego o termina.
    */

    printf ("\n");
    printf ("\nTurno: %i", turno);
    printf ("\nColor: %i\n", color);


    do {


        if (turno == 1 && color == 1) {     // Si turno = 1 y color = 1, empieza el usuario y juega con negras.

            pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);


            if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
                && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 2) && tablero [fila_actual][colum_actual] == 'N') {

                cambioDePosicionHumano (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux, tablero);


                // Juega la máquina...
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

            }

            //Revisa este cuando se quiera hacer un salto.

            else if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
            && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 8) && tablero [fila_actual][colum_actual] == 'N') {


                // Este while se repite cada vez que el usuario realiza un movimiento invalido, se vuelve a pedir las posiciones.
                x = 0; // ceramos "X"

                while (x == 0) {  // cuando sea x == 1 se rompe el ciclo

                    saltarFichas (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, &x, aux, tablero);

                    if (x == 1) {

                        volverAsaltar (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux3, tablero);
                    }

                    if (x == 0) {  // despues de pasar a esta linea "x" puede ser cero o uno. Si es uno entonces colocó de forma correcta las posiciones...

                        printf ("\n\nNo se pudo realizar el salto, movimiento invalido");
                        printf ("\nPor favor, vuelva a intentar");
                        pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);

                    }

                }




                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);



            }

            else {
                printf ("\nMovimiento no válido");
            }



        }
        else if (turno == 1 && color == 2) {        // Si turno = 1 y color = 2, empieza el usuario y juega con blancas.

            pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);


            if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
                && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 2) && tablero [fila_actual][colum_actual] == 'B') {

                cambioDePosicionHumano (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux, tablero);


                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);


            }

            //Revisa este cuando se quiera hacer un salto.

            else if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
            && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 8) && tablero [fila_actual][colum_actual] == 'B') {


                // Este while se repite cada vez que el usuario quiera realizar un movimiento invalido, vuelve a pedir las posiciones.
                x = 0; // ceramos "X"
                while (x == 0) {  // cuando sea x == 1 se rompe el ciclo

                    saltarFichas (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, &x, aux, tablero);

                    if (x == 1) {

                        volverAsaltar (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux3, tablero);
                    }

                    if (x == 0) {  // despues de pasar a esta linea "x" puede ser cero o uno. Si es uno entonces colocó de forma correcta las posiciones...

                        printf ("\n\nNo se pudo realizar el salto, movimiento invalido");
                        printf ("\nPor favor, vuelva a intentar");
                        pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);

                    }

                }

                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

            }

            else {
                printf ("\nMovimiento no válido");
            }


        }
        else if (turno == 2 && color == 1) {                    // turno = 2 y color = 1, empieza la máquina y juega con negras.

        	if (a==0){


                    aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                    juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                    cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);


                    // cuando sea turno de la maquina, se imprime ya el tablero para ver la jugada que hizo.

                    printf ("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16");  // Enumera la parte de arriba del tablero.
                            for (int i = 1; i <= 16; i++) {
                                printf ("\n\n ");
                                printf("%d\t",i);

                                for (int j = 1; j <= 16; j++) {

                                    printf ("%c\t", tablero [i][j]);

                            }
                        }
                    a=1;
        	}
                    pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);


            if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
                && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 2) && tablero [fila_actual][colum_actual] == 'B') {

                cambioDePosicionHumano (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux, tablero);


                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

            }

            //Revisa este cuando se quiera hacer un salto.

            else if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
            && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 8) && tablero [fila_actual][colum_actual] == 'B') {

                // Este while se repite cada vez que el usuario quiera realizar un movimiento invalido, vuelve a pedir las posiciones.
                x = 0; // ceramos "X"
                while (x == 0) {  // cuando sea x == 1 se rompe el ciclo

                    saltarFichas (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, &x, aux, tablero);

                    if (x == 1) {

                        volverAsaltar (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux3, tablero);
                    }

                    if (x == 0) {  // despues de pasar a esta linea "x" puede ser cero o uno. Si es uno entonces colocó de forma correcta las posiciones...

                        printf ("\n\nNo se pudo realizar el salto, movimiento invalido");
                        printf ("\nPor favor, vuelva a intentar");
                        pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);

                    }

                }


                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaN (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

            }

            else {
                printf ("\nMovimiento no válido"); //imprime este al final (para opcion 2)
            }
        }



        else if (turno == 2 && color == 2) {                    // turno = 2 y color = 2, empieza la máquina y juega con blancas.

        	if (a==0){

                // juega la maquina
                aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

                printf ("\n\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16");  // Enumera la parte de arriba del tablero.
                    for (int i = 1; i <= 16; i++) {
                        printf ("\n\n ");
                        printf("%d\t",i);

                        for (int j = 1; j <= 16; j++) {

                            printf ("%c\t", tablero [i][j]);

                    }
                }
                a=1;
    	   }

            pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);


            if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
                && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 2) && tablero [fila_actual][colum_actual] == 'N') {

                    cambioDePosicionHumano (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux, tablero);


                    // juega la maquina
                    aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                	juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                    cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);
            }

                //Revisa este cuando se quiera hacer un salto.

            else if ((fila_actual >= 1 && fila_actual <= 16) && (colum_actual >= 1 && colum_actual <= 16) && (fila_nueva >= 1 && fila_nueva <= 16) && (colum_nueva >= 1 && colum_nueva <= 16) && (tablero [fila_nueva][colum_nueva] == '.')
            && ((pow((fila_nueva - fila_actual), 2) + pow((colum_nueva - colum_actual), 2)) <= 8) && tablero [fila_actual][colum_actual] == 'N') {


                    // Este while se repite cada vez que el usuario quiera realizar un movimiento invalido, vuelve a pedir las posiciones.
                    x = 0; // ceramos "X"
                    while (x == 0) {  // cuando sea x == 1 se rompe el ciclo

                    saltarFichas (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, &x, aux, tablero);

                    if (x == 1) {

                        volverAsaltar (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva, aux3, tablero);
                    }

                    if (x == 0) {  // despues de pasar a esta linea "x" puede ser cero o uno. Si es uno entonces colocó de forma correcta las posiciones...

                        printf ("\n\nNo se pudo realizar el salto, movimiento invalido");
                        printf ("\nPor favor, vuelva a intentar");
                        pedidos (&fila_actual, &colum_actual, &fila_nueva, &colum_nueva);

                    }

                }

                    // juega la maquina
                    aleatorioMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1);
                    juegaMaquinaB (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, tablero);
                    cambioDePosicionMaquina (&fila_actual1, &colum_actual1, &fila_nueva1, &colum_nueva1, aux2, tablero);

            }


            else {
                printf ("\nMovimiento no válido"); //imprime este al final (para opcion 2)
            }

        }




        printf ("\nApriete '1' para terminar turno o '2' para rendirse: "), scanf ("%i", &t);     // Opción de terminar turno o rendirse.
        if (t == 2) {
            printf ("\nSe ha rendido.");
            consumirNuevaLinea();
            break;

        }


       // imprime el tablero con los movimientos ya realizados.
       tableroActualizado (tablero);

       // verificamos si hay un ganador
       result = condicionQuienGana(tablero);

    consumirNuevaLinea();

    }

    while(t == 1 && result != 20); // cuando t == 1 y result != 20 (sigue el juego) y cuando result == 20 significa que ganó las blancas o las negras y se corta el do-while
    							// cuando t == 2 (se rinde el humano)
    return 0;
}
