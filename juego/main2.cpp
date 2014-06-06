#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum jugadas{PIEDRA, PAPEL, TIJERA};

void titulo(){


	printf("\t**********************************\n");
	printf("\t*********** BIENVENIDO ***********\n");
	printf("\t*************** A ****************\n");
	printf("\t******* PIEDRA PAPEL TIJERA ******\n");
	printf("\t**********************************\n");

}

int menu(){

	int opcion = 0;
	printf(" \t Selecciona una opcion: \n");
	printf(" \t 1-> Normas del juego. \n");
	printf(" \t 2-> Jugar al juego. \n");
	printf(" \t 3-> Salir. \n");
	printf("\t Tu opcion: ");
	scanf("%i", &opcion);

	printf("\n\n");
	return opcion;
}

int jugadaHumano(){


	int opcion;
	printf(" \t Opciond e jugada: \n");
	printf(" \t 1-> Piedra. \n");
	printf(" \t 2-> Papel. \n");
	printf(" \t 3-> Tijera. \n");
	printf("\t Tu opcion: ");
	scanf("%i", &opcion);

	printf("\n\n");
	return opcion + 1;
}

int jugadaMaquina(){

	int opcion;

	//Genera un número aleatorio entre el 1 y el 3

	srand(time(NULL));

	return opcion  = (rand() % 3) + 1;

}

void normas(){


	FILE *archivo;
	char caracter;

	archivo = fopen("normas.txt","r");

	if (archivo == NULL){

		printf("\n Error de apertura del archivo. \n\n");
	}else{


		printf("\n Las normas del juego son:  \n\n");

		while (feof(archivo) == 0)
		{
			caracter = fgetc(archivo);
			printf("%c",caracter);
		}
	}
	fclose(archivo);
	printf("\n\n");

}

/*
 *Creamos la lógica del juego
 *Donde pedimos al usuario que introduzca su jugada
 *y la comparamos con un número aleatorio entre el 1 y el 3
 *que representan la jugada de la máquina
 *y mostramos el ganador
 */
void juego(){

	jugadas juegaH;
	jugadas juegaM;
	int jugadahumana = jugadaHumano();

	switch(jugadahumana){

		case 1:
			juegaH=PIEDRA;
			break;
		case 2:
			juegaH=PAPEL;
			break;
		case 3:
			juegaH=TIJERA;
			break;
	}

	int jugadamaquina = jugadaMaquina();

	//Comparar las jugadas

	if (jugadahumana==jugadamaquina){

		printf("Esto es un empate ha salido: ", juegaH);

	}else if (jugadahumana==1 && jugadamaquina==2){

		printf("Gana la máquina: Humano %i y la maquina %i",juegaH, juegaM);


	}else if (jugadahumana==1 && jugadamaquina==3){

		printf("Gana el humano: Humano %i y la maquina %i",juegaH, juegaM);

	}else if (jugadahumana==1 && jugadamaquina==0){

		printf("Gana la máquina: Humano %i y la maquina %i",juegaH, juegaM);


	}else if (jugadahumana==1 && jugadamaquina==2){

		printf("Gana la máquina: Humano %i y la maquina %i",juegaH, juegaM);


	}else if (jugadahumana==2 && jugadamaquina==0){

		printf("Gana la máquina: Humano %i y la maquina %i",juegaH, juegaM);


	}else if (jugadahumana==2 && jugadamaquina==1){

		printf("Gana la máquina: Humano %i y la maquina %i",juegaH, juegaM);


	}

printf("\n");
}




int salir(){

	return EXIT_FAILURE;

}



int main(){

	int opcion=0;


	system("clear");
	titulo();
	srand(time(NULL));
	printf("\n\n");




	while(opcion <1 || opcion >3){

		opcion = menu();

		switch(opcion){

			case 1: normas();  break;
			case 2: juego();   break;
			case 3: salir();   break;

		}
	}


	return EXIT_SUCCESS;
}

