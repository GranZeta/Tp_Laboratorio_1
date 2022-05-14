#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "bibliotecaPersonal.h"


int initPassengers (ePassenger listaPasajeros [],int tamanio)
{
	int i;
	int retorno=-1;

	if(tamanio > 0 && listaPasajeros!= NULL)
	{
		retorno=0;
		for(i=0;i<tamanio;i++)
		{
			listaPasajeros[i].isEmpty = 0;
		}
	}

	return retorno;
}

int addPassenger(ePassenger listaPasajeros [], int tamanio, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int index = -1;
	int i;

	for(i=0;i<tamanio;i++) //1
	{
		if(listaPasajeros[i].isEmpty == 0)
		{
			index = i;//1
			break;
		}

	}
	return index;

	return -1;
}


int findPassengerById(ePassenger listaPasajeros [],int tamanio, int id)
{
	int retorno=-1;
	int i;


		for(i=0;i<tamanio;i++)
		{
			if(listaPasajeros[i].isEmpty == 1 && id == listaPasajeros[i].id)
			{
				retorno=i;
				break;
			}
		}


	return retorno;
}

int removePassenger (ePassenger listaPasajeros [],int tamanio, int id)
{
	int retorno=-1;
	int idPasajero;
	int i;

	idPasajero=findPassengerById(listaPasajeros,tamanio,id);

	if(idPasajero != 1)
	{
		for(i=0;i<tamanio;i++)
		{
			if(idPasajero == i)
			{
				listaPasajeros[i].isEmpty = -1;
				retorno=0;
			}
		}
	}
	return retorno;
}

int sortPassengers(ePassenger listaPasajeros [],int tamanio, int orden)
{
	int retorno;

	retorno=ordenarApellidoYTipo(listaPasajeros,tamanio,orden);

	return retorno;
}

int printPassengers(ePassenger listaPasajeros [],int tamanio, etypeVuelo listaTipoVuelo[],etypePasajero listaTipoPasajero[], int tamanioT )
{
	int i;
	int j;
	int k;
	int ancho=-25;
	int anchoId=-10;
	int retorno=-1;
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
	printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",anchoId,"ID", ancho,"Nombre",ancho,"Apellido",ancho,"Precio",anchoId,"Codigo",anchoId,"Tipo",anchoId,"Estado");
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
	for(i=0;i<tamanio;i++)
	{
		if(listaPasajeros[i].isEmpty==1)
		{
			for(j=0;j<tamanioT;j++)
			{
				if(listaPasajeros[i].statusFlight == listaTipoVuelo[j].statusFlight)
				{
					for(k=0;k<tamanioT;k++)
					{
						if(listaPasajeros[i].typePassenger == listaTipoPasajero[k].typePassenger)
						{
							printf("|%*d|%*s|%*s|%*.2f|%*s|%*s|%*s|\n",anchoId,listaPasajeros[i].id,ancho,listaPasajeros[i].name,ancho,listaPasajeros[i].lastname,ancho,listaPasajeros[i].price,anchoId,listaPasajeros[i].flycode,anchoId,listaTipoPasajero[k].descripcionP,anchoId,listaTipoVuelo[j].descripcion);
							retorno=0;
						}
					}
				}
			}
		}
	}
	printf("+----------+-------------------------+-------------------------+-------------------------+----------+----------+----------+\n");
	return retorno;
}


int sortPassengersByCode(ePassenger listaPasajeros [],int tamanio, int orden)
{
	int retorno;

	retorno=ordenamientoCodigo(listaPasajeros,tamanio,orden);

	return retorno;
}
