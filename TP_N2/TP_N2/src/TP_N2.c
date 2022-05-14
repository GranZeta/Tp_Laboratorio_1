/*
 ============================================================================
 Name        : TP_N2.c
 Author      : Pablo Martin Quiñonez
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "ArrayPassenger.h"

#define TAM 2000
#define TAM2 3

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int contador=5;
	int contadorID=6;

	ePassenger pasajero[TAM];
	etypeVuelo tipoPasajero[TAM2];
	etypePasajero tipoVuelo[TAM2];


	initPassengers(pasajero,TAM);
	cargaPasajeros(pasajero,5);
	cargaTipoPasajero(tipoPasajero,TAM2);
	cargaTipoVuelo(tipoVuelo,TAM2);

	do
	{
		opcion= mostrarMenu(opcion);

		switch(opcion)
		{
		case 1:
			if(altaPasajero(pasajero,TAM,contadorID)==1)
			{
				contador++;
				contadorID++;
				printf("Carga exitosa!!!\n");
			}
			else
			{
				printf("Lista llena!!!\n");
			}
		break;

		case 2:

			if(contador>0)
			{
				if(modificar(pasajero,TAM,tipoPasajero,tipoVuelo,TAM2)==1)
				{
					printf("Datos cambiado exitasoamnete...\n");
				}
				else
				{
					printf("No hay personas cargadas con este codigo...\n");
				}
			}
			else
			{
				printf("No hay nadie dado de alta...\n");
			}
		break;

		case 3:

			if(contador>0)
			{
				if(baja(pasajero,TAM,tipoPasajero,tipoVuelo,TAM2)==0)
				{
					contador--;
					printf("Borramos los datos deseados...\n");
				}
				else
				{
					printf("No hay personas cargadas con estos datos...\n");
				}
			}
			else
			{
				printf("No hay nadie dado de alta...\n");
			}

			break;

		case 4:
			if(contador>0)
			{
				informar(pasajero,TAM,tipoPasajero,tipoVuelo,TAM2,contador);
			}
			else
			{
				printf("No hay nadie dado de alta...\n");
			}
			break;

		case 5:
			printf("Fin del programa...\n");
		break;


		default:
			printf("\nOpcion incorrecta...");
		break;
		}


	}while(opcion != 5);


	return EXIT_SUCCESS;
}
