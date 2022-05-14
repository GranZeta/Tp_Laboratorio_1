#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validaciones.h"
#include "ArrayPassenger.h"

int ValidarNumero(char numero[])
{
    int retorno=1;
    int len;
    if(numero!=NULL){
        len=strlen(numero);
        for(int i=0;i<len;i++){ //"51"
            if(!isdigit(numero[i])){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int PedirEntero(char mensaje[],char mensajeError[])
{
    int retorno;
    char numero[1000];
    printf(mensaje);
    scanf("%s",numero);
    while(!ValidarNumero(numero)){
        printf(mensajeError);
        printf(mensaje);
        scanf("%s",numero);
    }
    retorno=atoi(numero);
    return retorno;
}



void PedirLetras(char mensaje[],char mensajeError[], char destino[] )
{

    char letra[1024];
    int cadena;

    printf(mensaje);
    fflush(stdin);
    scanf("%[^\n]",letra);
    cadena= validarCadena(letra);

    while(!ValidarLetra(letra) || cadena == 0){
        printf(mensajeError);
        printf(mensaje);
        fflush(stdin);
        scanf("%[^\n]",letra);
        cadena= validarCadena(letra);
    }

    strcpy(destino,letra);
}


int confirmacion()
{
	char confirmacion;
	int retorno;

	printf("¿Esta seguro de Realizalo? [s|n]: ");
	fflush(stdin);
	scanf("%c", &confirmacion);
	if(confirmacion == 's')
	{
		retorno=1;
	}
	else
	{
		retorno=0;
	}

	return retorno;
}



int ValidarLetra(char nombre[])
{
	int i;

	for (i=0 ; i<strlen(nombre); i++)
	{
		if(!((nombre[i]>=65 && nombre[i]<=90) || (nombre[i]>=97 && nombre[i]<=122)|| nombre[i]==' '))
		{

		   return 0;
		   break;
		}
	}

    return 1;
}

void validarCadenaCaracteres(char mensaje[],char mensajeError[], char cadena[])
{
	char aux[1024];
	int cantidad;
	printf(mensaje);
	fflush(stdin);
	scanf("%[^\n]",aux);
	cantidad = strlen(aux);

	while(cantidad > 10)
	{
		printf(mensajeError);
		printf(mensaje);
		fflush(stdin);
		scanf("%[^\n]",aux);
		cantidad = strlen(aux);
	}

	strcpy(cadena,aux);
}


int validarCadena(char letra[])
{

	int cantidad;
	int retorno;

	cantidad = strlen(letra);

	if(cantidad > 51)
	{
		retorno=0;
	}
	else
	{
		retorno=1;
	}
	return retorno;
}


float PedirFlotante(char mensaje[],char mensajeError[], int min, int max)
{
	float numero;

	numero=PedirEntero(mensaje,mensajeError);

	while(numero > max || numero < min)
	{
		printf(mensajeError);
		printf(mensaje);
		scanf("%f",&numero);
	}
	return numero;
}

int minMax(char mensaje[],char mensajeError[],int min, int max)
{

	int validar;
	int retorno;


	validar=PedirEntero(mensaje,mensajeError);

	while( validar < min || validar > max)
	{
		printf(mensajeError);
		printf(mensaje);
		scanf("%d",&validar);
	}

	retorno=validar;

	return retorno;
}
